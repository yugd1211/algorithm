#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
int M;

int p[1001];
int vis[1001];
vector<pair<int, int>> vec[1001];
priority_queue<pair<int, int>,
			   vector<pair<int, int>>,
			   greater<pair<int, int>>>
	pq;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	fill(vis, vis + 1001, 2100000000);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		vec[u].push_back({v, c});
		vec[v].push_back({u, c});
	}
	vis[1] = 0;
	pq.push({0, 1});

	while (!pq.empty())
	{
		int cost, dest;
		tie(cost, dest) = pq.top();
		pq.pop();
		if (cost > vis[dest])
			continue;

		for (int i = 0; i < vec[dest].size(); i++)
		{
			int nd, nc;
			tie(nd, nc) = vec[dest][i];
			if (vis[nd] > vis[dest] + nc)
			{
				vis[nd] = vis[dest] + nc;
				p[nd] = dest;
				pq.push({vis[nd], nd});
			}
		}
	}

	vector<pair<int, int>> res;
	for (int i = 2; i <= N; ++i)
	{
		if (p[i] != -1)
			res.push_back({i, p[i]});
	}

	cout << res.size() << "\n";
	for (auto [a, b] : res)
		cout << a << " " << b << "\n";
}