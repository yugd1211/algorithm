#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N, M;

vector<pair<int, int>> edge[100001];
// cost, st, en
priority_queue<tuple<int, int, int>> pq;

int vis[100001];

void InsertLine(int u, int v, int c)
{
	for (int i = 0; i < edge[u].size(); i++)
	{
		pair<int, int> &p = edge[u][i];

		if (p.first == v)
		{
			if (p.second < c)
				p.second = c;
			return;
		}
	}
	edge[u].push_back({v, c});
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		InsertLine(u, v, c);
		InsertLine(v, u, c);
	}
	int st, en;
	cin >> st >> en;
	for (int i = 0; i < edge[st].size(); i++)
	{
		pair<int, int> curr = edge[st][i];
		int nxt = curr.first;
		int cost = curr.second;

		pq.push({cost, st, nxt});
	}
	vis[st] = 1000000000;

	while (!pq.empty())
	{
		int st, en, cost;
		tie(cost, st, en) = pq.top();
		pq.pop();
		if (vis[en] >= min(cost, vis[st]))
			continue;
		vis[en] = min(cost, vis[st]);
		int nst = en;
		for (int i = 0; i < edge[en].size(); i++)
		{
			int nen = edge[en][i].first;
			int ncost = edge[en][i].second;
			if (vis[nen] < min(ncost, vis[nst]))
				pq.push({min(ncost, vis[nst]), nst, nen});
		}
	}
	cout << vis[en];
}