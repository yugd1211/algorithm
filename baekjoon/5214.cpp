#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, K, M;

vector<int> lst[100001];
int vis[100001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    cin >> N >> K >> M;
    for (int i = 0; i < M; i++)
    {
        vector<int> vec;
        for (int j = 0; j < K; j++)
        {
            int n;
            cin >> n;
            vec.push_back(n);
        }
        for (int k = 0; k < vec.size(); k++)
        {
            int curr = vec[k];
            for (int j = 0; j < vec.size(); j++)
            {
                int nxt = vec[j];
                if (curr == nxt)
                    continue;
                lst[curr].push_back(nxt);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        sort(lst[i].begin(), lst[i].end());
        auto last = unique(lst[i].begin(), lst[i].end());
        lst[i].erase(last, lst[i].end());
    }
    vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < lst[curr].size(); i++)
        {
            int nxt = lst[curr][i];
            if (vis[nxt])
                continue;
            vis[nxt] = vis[curr] + 1;
            q.push(nxt);
        }
    }
    cout << vis[N];
}