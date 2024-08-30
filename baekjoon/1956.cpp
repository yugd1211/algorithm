#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000001

vector<pair<int, int>> adj[401];
int d[401][401];
int V, E;

void input()
{
	cin >> V >> E;
	while (E--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
	}
}

void find_shortest_path(int st)
{
	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>>
		pq;
	fill(d[st], d[st] + V + 1, INF);
	d[st][st] = 0;
	pq.push({0, st});
	while (!pq.empty())
	{
		int cost, dest;
		tie(cost, dest) = pq.top();
		pq.pop();
		if (cost != d[st][dest])
			continue;
		for (auto nxt : adj[dest])
		{
			int nc, nd;
			tie(nc, nd) = nxt;
			nc += d[st][dest];
			if (d[st][nd] <= nc)
				continue;
			d[st][nd] = nc;
			pq.push({nc, nd});
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int ans = INF;
	input();
	for (int i = 1; i <= V; i++)
		find_shortest_path(i);
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
				continue;
			ans = min(ans, d[i][j] + d[j][i]);
		}
	}
	cout << (ans >= INF ? -1 : ans);
}