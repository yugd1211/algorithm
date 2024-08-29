#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000001

// 문제 풀이
// 다익스트라 알고리즘으로 풀었다.
// d를 채워나가는 방식이 특이한데, 이전 간선의 값과 현재 간선의 값을 비교해야 했다.
// 이전 간선의 값이 현재 간선의 값보다 작다면 d[curr] = d[prev] + next_edge - prev_edge,
// 크다면 d[curr] = d[prev] + M - prev_edge이다.
// 간선의 크기순서대로 신호등이 바뀌기 때문에 현재 간선이 이전간선보다 크다면 현재 순회에서 바로 다음 노드까지 갈 수 있는 것이고,
// 아니라면 다음 순회에 넘어가야 되기 때문에 이러한 조건문이 필요하다.g

vector<pair<long long, long long>> adj[100001];
long long d[100001];

int N; // 100000
int M; // 700000

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back({i, b});
		adj[b].push_back({i, a});
	}
}

void find_shortest_distance(int st)
{
	priority_queue<
		pair<long long, long long>,
		vector<pair<long long, long long>>,
		greater<pair<long long, long long>>>
		pq;
	fill(d, d + N + 1, INF);
	d[st] = 0;
	pq.push({0, st});
	while (!pq.empty())
	{
		long long cost, dest;
		tie(cost, dest) = pq.top();
		pq.pop();
		if (cost != d[dest])
			continue;
		for (auto nxt : adj[dest])
		{
			long long nc, nd;
			tie(nc, nd) = nxt;
			int prev_edge = d[dest] % M;
			if (prev_edge > nc)
				nc += d[dest] + (M - prev_edge);
			else
				nc = d[dest] + nc - prev_edge;
			if (nc >= d[nd])
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
	find_shortest_distance(1);
	cout << d[N] + 1;
}