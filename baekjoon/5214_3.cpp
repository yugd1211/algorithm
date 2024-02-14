#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, K, M;

int vis[100001];
vector<vector<int>> lst;

void printVis()
{
    cout << "==============\n";
    for (int i = 1; i <= N; i++)
        cout << i << " ";
    cout << "\n";
    for (int i = 1; i <= N; i++)
    {
        if (i < 10)
            cout << vis[i] << " ";
        else
            cout << " " << vis[i] << " ";
    }
    cout << "\n";
}

void printList()
{
    for (int i = 0; i < lst.size(); i++)
    {
        cout << i << " = ";
        for (int j = 0; j < lst[i].size(); j++)
        {
            cout << lst[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    cin >> N >> K >> M;
    vis[1] = 1;
    for (int i = 0; i < M; i++)
    {
        vector<int> vec;
        for (int j = 0; j < K; j++)
        {
            int n;
            cin >> n;
            vec.push_back(n);
        }
        sort(vec.begin(), vec.end());
        lst.push_back(vec);
    }
    sort(lst.begin(), lst.end());
    for (int i = 0; i < lst.size(); i++)
    {
        int _min = lst[i][0];
        for (int j = 0; j < lst[i].size(); j++)
        {
            int curr = lst[i][j];
            if (vis[curr] && vis[curr] < vis[_min])
                _min = curr;
        }
        for (int j = 0; j < lst[i].size(); j++)
        {
            int curr = lst[i][j];
            if (vis[curr] == 0 || vis[curr] > vis[_min] + 1)
                vis[curr] = vis[_min] + 1;
        }
    }
    cout << vis[N];
}