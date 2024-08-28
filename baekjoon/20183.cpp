#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000000005

vector<pair<long long, long long>> adj[100001];
long long d[100001];

long long N, M, A, B, C;

void input()
{
	cin >> N >> M >> A >> B >> C;
	while (M--)
	{
		long long u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({c, v});
		adj[v].push_back({c, u});
	}
}

bool max_edge_find_path(long long st, long long en, long long max_edge_len)
{
	priority_queue<
		pair<long long, long long>,
		vector<pair<long long, long long>>,
		greater<pair<long long, long long>>>
		pq;

	fill(d, d + 100001, INF);
	pq.push({0, st});
	d[st] = 0;
	while (!pq.empty())
	{
		long long cost = pq.top().first;
		long long dest = pq.top().second;
		pq.pop();
		if (cost != d[dest])
			continue;
		for (auto nxt : adj[dest])
		{
			long long nc = nxt.first;
			long long nd = nxt.second;
			if (nc > max_edge_len)
				continue;
			nc += d[dest];
			if (nc > C || d[nd] <= nc)
				continue;
			d[nd] = nc;
			pq.push({nc, nd});
		}
	}
	return d[en] >= INF ? 0 : 1;
}

long long binary_search()
{
	long long l = 1;
	long long r = C + 1;
	while (l < r)
	{
		long long mid = (l + r) / 2;
		if (max_edge_find_path(A, B, mid))
			r = mid;
		else
			l = mid + 1;
	}
	if (r > C)
		return -1;
	return r;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	cout << binary_search();
}