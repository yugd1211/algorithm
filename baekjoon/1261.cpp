#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000

// 문제풀이
// 상하좌우를 간선으로 벽을 간선의 값으로하는 그래프의 다익스트라 알고리즘을 적용했다.

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M; // 100
int adj[101][101];
int vis[101][101];
priority_queue<
	tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>>
	pq;

void input()
{
	cin >> M >> N;
	for (int i = 1; i <= N; i++)
		fill(vis[i], vis[i] + M + 1, INF);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char c;
			cin >> c;
			adj[i][j] = c - '0';
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	vis[1][1] = 0;
	pq.push({0, 1, 1});

	while (!pq.empty())
	{
		int cost, x, y;
		tie(cost, x, y) = pq.top();
		pq.pop();
		if (vis[x][y] != cost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = cost + adj[nx][ny];

			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;
			if (nc >= vis[nx][ny])
				continue;
			vis[nx][ny] = nc;
			pq.push({nc, nx, ny});
		}
	}
	cout << vis[N][M];
}