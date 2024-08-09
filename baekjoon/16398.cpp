#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 문제 풀이
// MST(최소신장트리)문제였다.
// 프림 알고리즘(임의의 간선을 선택해 간선간의 비용중 제일 작은것을 선택하며 MST를 채워나가는 방식)을 사용해 풀었다.

int N;
long long ans;
bool MST[1001];
// cost, dest
vector<pair<int, int>> adj[100002];
// cost, u, v
priority_queue<
	tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>>
	pq;

void input()
{
	cin >> N;
	for (int u = 1; u <= N; u++)
	{
		for (int v = 1; v <= N; v++)
		{
			int cost;
			cin >> cost;
			if (u == v)
				continue;
			adj[u].push_back({cost, v});
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	MST[1] = 1;
	for (auto nxt : adj[1])
	{
		int cost, dest;
		tie(cost, dest) = nxt;
		pq.push({cost, 1, dest});
	}
	while (!pq.empty())
	{
		int cost, u, v;
		tie(cost, u, v) = pq.top();
		pq.pop();
		if (MST[v])
			continue;
		MST[v] = 1;
		ans += cost;
		for (auto nxt : adj[v])
		{
			int cost, dest;
			tie(cost, dest) = nxt;
			if (MST[dest])
				continue;
			pq.push({cost, v, dest});
		}
	}
	cout << ans;
}
