#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 100000000001

// 시간초과 발생
// 문제풀이
// 1. 모든 정점에서 면접장 별로 다익스트라 알고리즘을 적용한다.
// 2. 그중 제일 작은 수를 저장한다.
// 3. 2번에서 저장한 수들중 제일 작은 곳을 찾는다.
// 시간초과 날것도 같았다.
// 일단 N(정점)이 100000이고, K(면접장) 또한 99999이다. K = N - 1 이므로 N으로 대체가능하다.
// 결국 총 시간복잡도는  N ^ 2 * N log V(다익스트라 시간복잡도)이다..
// 다익스트라를 더 조금 호출해야한다. N번 호출까지는 어찌저찌 될것도같기 때문에 이걸로 해봐야하지 않나싶다.
// 이전의 다익스트라 문제를 풀었을때 간선의 방향을 모두 반대로 하는 그래프를 만들어 다익스트라 알고리즘을 실행하면,
// 시작 정점에서 모든 정점까지의 최소 거리가 아니라
// 모든 정점에서 시작 정점까지의 최소 거리가 구해지는 구현법을 봤었다.
// 이 방식을 채텍한다면  면접장들로부터 다익스트라를 실행하고 d를 업데이트 하는방식으로 진행하면 될것같기도 이방식으로 진행한다.baekjoon/17835.cpp

//
// 최단 거리 알고리즘
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

void find_short_dis(int st)
{
	fill(d, d + 100001, INF);
	d[st] = 0;
	pq.push({0, st});
	while (!pq.empty())
	{
		long long dest, cost;
		tie(cost, dest) = pq.top();

		pq.pop();
		if (cost != d[dest])
			continue;
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
	for (int i = 0; i < meet.size(); i++)
		find_short_dis(meet[i]);
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