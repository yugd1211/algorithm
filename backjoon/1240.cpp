#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second

using namespace std;

// 정점, 거리
vector<pair<int, int>> adj[1001];
int N, M;

void dfs(int st, int en, int (&dist)[1001], int (&p)[1001])
{
    for (int i = 0; i < adj[st].size(); i++)
    {
        int c, d;
        tie(c, d) = adj[st][i];
        if (c == p[c])
            continue;
        if (dist[c])
            continue;
        p[c] = st;
        dist[c] = d + dist[st];
        dfs(c, en, dist, p);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i < N; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    for (int i = 0; i < M; i++)
    {
        int dist[1001];
        int p[1001];
        fill(dist, dist + 1001, 0);
        fill(p, p + 1001, 0);
        int a, b;
        cin >> a >> b;
        p[a] = a;
        dfs(a, b, dist, p);
        cout << dist[b] << "\n";
    }
}