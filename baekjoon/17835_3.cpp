#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000001

// 문제풀이
// 그래프를 역방향으로 바꾼다. (역방향 그래프로 바꿨을때 다익스트라 알고리즘을 실행하면 모든정점에서 해당 정점까지의 최단 거리가 구해진다.)
// 각 정점마다 다익스트라를 호출하면 N * NlogN이기 때문에 시간초과발생
// 다익스트라의 시작정점을 여러개로 두고 다익스트라를 한번만 실행한다.
// 이 결과물은 모든 목표 정점중 제일 작은 값으로 갈수 있는 값이 담긴다.

// 최단 거리중 제일 먼 도시, 해당 거리
// 단방향 간선
// 도시 수, 간선 수, 면접장 수
int N, M, K;
vector<pair<int, long long>> adj[100001];
priority_queue<
	pair<long long, int>,
	vector<pair<long long, int>>,
	greater<pair<long long, int>>>
	pq;
long long d[100001];
vector<int> meet;
long long sd[100001];

void input()
{
	cin >> N >> M >> K;
	fill(sd, sd + 100001, INF);
	while (M--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		adj[v].push_back({u, c});
	}
	while (K--)
	{
		int n;
		cin >> n;
		meet.push_back(n);
	}
}

void print_d()
{
	for (int i = 1; i <= N; i++)
		cout << d[i] << ", ";
	cout << "\n";
}

void find_short_dis()
{
	int end = 0;
	fill(d, d + 100001, INF);
	for (auto nxt : meet)
	{
		d[nxt] = 0;
		pq.push({0, nxt});
	}
	while (!pq.empty())
	{
		long long dest, cost;
		tie(cost, dest) = pq.top();

		pq.pop();
		if (cost != d[dest])
			continue;
		end = dest;
		for (int i = 0; i < adj[dest].size(); i++)
		{
			long long nd, nc;
			tie(nd, nc) = adj[dest][i];
			nc += d[dest];
			if (d[nd] <= nc)
				continue;
			d[nd] = nc;
			pq.push({nc, nd});
		}
	}
	for (int i = 1; i <= N; i++)
		sd[i] = min(d[i], sd[i]);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	find_short_dis();
	int ans = 1;
	for (int i = 1; i <= N; i++)
	{
		if (sd[ans] >= sd[i])
			continue;
		ans = i;
	}
	cout << ans << '\n';
	cout << sd[ans];
}