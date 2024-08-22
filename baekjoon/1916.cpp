#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000001

// cost, dest
vector<pair<int, int>> adj[1001];
int N, M;
int S, E;
int d[1001];

void input()
{
	cin >> N >> M;
	while (M--)
	{
		int u, v, c;

		cin >> u >> v >> c;
		adj[u].push_back({c, v});
	}
	cin >> S >> E;
}

void path_find(int st)
{
	fill(d, d + N + 1, INF);
	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>>
		pq;
	// cost, start edge
	pq.push({0, st});
	d[st] = 0;
	while (!pq.empty())
	{
		int cost, dest;
		tie(cost, dest) = pq.top();
		pq.pop();
		if (d[dest] != cost)
			continue;
		for (auto nxt : adj[dest])
		{
			int nc, nd;
			tie(nc, nd) = nxt;
			nc += d[dest];
			if (d[nd] <= nc)
				continue;
			d[nd] = nc;
			pq.push({nc, nd});
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	path_find(S);

	cout << d[E];
}