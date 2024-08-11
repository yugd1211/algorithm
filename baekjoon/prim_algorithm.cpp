#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

vector<pair<int, int>> adj[100005];
bool MST[1001];
int cnt;
int ans;

priority_queue<tuple<int, int, int>,
			   vector<tuple<int, int, int>>,
			   greater<tuple<int, int, int>>>
	pq;

priority_queue<tuple<int, int, int>,
			   vector<tuple<int, int, int>>,
			   greater<tuple<int, int, int>>>
	ans_pq;

int N, M;
int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int cost, u, v;
		cin >> u >> v >> cost;
		adj[u].push_back({cost, v});
	}
	// 임의의 정점 1번에 연결된 모든 간선을 pq에 넣는다.
	MST[1] = 1;
	for (auto nxt : adj[1])
		pq.push({nxt.first, 1, nxt.second});
	while (!pq.empty())
	{
		int x, y, cost;
		tie(cost, x, y) = pq.top();
		pq.pop();
		if (MST[y])
			continue;
		ans += cost;
		ans_pq.push({cost, x, y});
		cnt++;
		MST[y] = 1;
		for (auto nxt : adj[y])
		{
			if (MST[nxt.second])
				continue;
			pq.push({nxt.first, y, nxt.second});
		}
	}
	while (!ans_pq.empty())
	{
		int cost, u, v;

		tie(cost, u, v) = ans_pq.top();
		ans_pq.pop();
		cout << u << " -> " << v << " : " << cost << "\n";
	}
	cout << ans;
}