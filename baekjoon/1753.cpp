#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f

// cost, dest
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<pair<int, int>> adj[20001];
vector<int> ans;

int V, E;
int d[20001];

void dijkstra_algorithm(int st)
{
	d[st] = 0;

	pq.push({0, st});
	while (!pq.empty())
	{
		int dest, cost;
		tie(cost, dest) = pq.top();
		pq.pop();
		if (d[dest] != cost)
			continue;
		for (auto nxt : adj[dest])
		{
			int nxtDest, nxtCost;
			tie(nxtCost, nxtDest) = nxt;
			nxtCost += d[dest];
			if (d[nxtDest] <= nxtCost)
				continue;
			d[nxtDest] = nxtCost;
			pq.push({d[nxtDest], nxtDest});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int st;
	cin >> V >> E >> st;
	fill(d, d + V + 1, INF);
	while (E--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({cost, v});
	}
	dijkstra_algorithm(st);
	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
			cout << "INF";
		else
			cout << d[i];
		cout << '\n';
	}
}