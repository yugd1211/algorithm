#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f

int N, M, X;

// cost, dest
vector<pair<int, int>> adj[1001];
int d[1001];
int b[1001];

void input()
{
	cin >> N >> M >> X;
	while (M--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({cost, v});
	}
}

int dijkstra_algorithm(int st)
{
	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>>
		pq;

	fill(d, d + N + 1, INF);
	int ret = 0;
	d[st] = 0;
	pq.push({0, st});
	while (!pq.empty())
	{
		int dest, cost;
		tie(cost, dest) = pq.top();
		pq.pop();
		for (auto nxt : adj[dest])
		{
			int nd, nc;
			tie(nc, nd) = nxt;
			nc += d[dest];
			if (d[nd] <= nc)
				continue;
			d[nd] = nc;
			pq.push({nc, nd});
		}
	}
	ret = d[X] + b[st];

	return ret;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int ans = 0;
	input();
	dijkstra_algorithm(X);
	for (int i = 1; i <= N; i++)
		b[i] = d[i];
	for (int i = 1; i <= N; i++)
		ans = max(dijkstra_algorithm(i), ans);
	cout << ans;
}