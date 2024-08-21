#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 0x1f2f2f2f

// INF값을 처음에 0x3f3f3f3f로 잡았었다.
// 이를 0x1f2f2f2f으로 바꿔서 통과했는데 이유인즉, 출력값이 3개의 값을 더해서 만들어지는데
// 이때 출력값이 inf overflow의 반값일경우 overflow가 발생한다. 그렇기 때문에 이를 방지하기위해 INF값 3개를 더해서 overflow 나지않는 수로 수정해줬다.
// 오버플로우를 좀 더 생각하고 작성하자 차라리 아예 모든 자료형들을 int가 아니라 long long으로 처리해도 괜찮을것같다.

vector<pair<int, int>> adj[801];
int d[3][801];
int so[3];
int dist[2];

int N, E;
void find_path(int st, int idx)
{
	priority_queue<
		pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>>
		pq;

	fill(d[idx], d[idx] + N + 1, INF);
	d[idx][st] = 0;
	pq.push({0, st});

	while (!pq.empty())
	{
		int cost, dest;
		tie(cost, dest) = pq.top();
		pq.pop();

		if (cost != d[idx][dest])
			continue;

		for (auto nxt : adj[dest])
		{
			int nd, nc;
			tie(nc, nd) = nxt;
			nc += d[idx][dest];
			if (d[idx][nd] > nc)
			{
				d[idx][nd] = nc;
				pq.push({nc, nd});
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> E;
	while (E--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		adj[u].push_back({cost, v});
		adj[v].push_back({cost, u});
	}
	so[0] = 1;
	cin >> so[1] >> so[2];
	for (int i = 0; i < 3; i++)
		find_path(so[i], i);
	dist[0] = d[0][so[1]] + d[1][so[2]] + d[2][N];
	dist[1] = d[0][so[2]] + d[2][so[1]] + d[1][N];

	int res = min(dist[0], dist[1]);
	if (res < INF)
		cout << min(dist[0], dist[1]);
	else
		cout << -1;
}