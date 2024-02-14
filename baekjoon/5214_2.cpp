#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, K, M;

set<int> lst[100001];
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
            for (int j = k + 1; j < vec.size(); j++)
            {
                int nxt = vec[j];
                lst[curr].insert(nxt);
            }
        }
    }
    vis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto iter = lst[curr].begin(); iter != lst[curr].end(); iter++)
        {
            int nxt = *iter;
            if (vis[nxt])
                continue;
            vis[nxt] = vis[curr] + 1;
            q.push(nxt);
        }
    }
    cout << vis[N];
}