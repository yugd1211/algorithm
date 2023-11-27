#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<int> adj[32001];
int indegree[32001];

int main()
{
    queue<int> q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        ++indegree[v];
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < adj[curr].size(); i++)
            if (--indegree[adj[curr][i]] == 0)
                q.push(adj[curr][i]);
    }
    return 0;
}