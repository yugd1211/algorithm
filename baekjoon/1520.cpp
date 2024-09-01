#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제풀이
// DP + 우선순위큐를 사용했다.
// 시작 지점부터 끝 지점까지 DP를 채우는데 채우는 순서를 상하좌우로 순회하는데 순회 순서를 우선순위 큐를 사용해 근접한 노드중 제일 높은 곳으로부터 시작한다.

long long dx[4] = {1, 0, -1, 0};
long long dy[4] = {0, 1, 0, -1};

long long N, M;
long long adj[501][501];
long long dp[501][501];

// c, x, y
priority_queue<tuple<long long, long long, long long>> pq;

void input()
{
	cin >> N >> M;
	for (long long i = 1; i <= N; i++)
		for (long long j = 1; j <= M; j++)
			cin >> adj[i][j];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	pq.push({adj[1][1], 1, 1});
	dp[1][1] = 1;
	while (!pq.empty())
	{
		long long c, x, y;
		tie(c, x, y) = pq.top();
		pq.pop();

		long long tmp = 0;

		for (long long i = 0; i < 4; i++)
		{
			long long nx = x + dx[i];
			long long ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;
			if (adj[x][y] >= adj[nx][ny])
				continue;
			tmp += dp[nx][ny];
		}
		if (x != 1 || y != 1)
		{
			if (tmp > dp[x][y])
				dp[x][y] = tmp;
			else
				continue;
		}
		for (long long i = 0; i < 4; i++)
		{
			long long nx = x + dx[i];
			long long ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > N || ny > M)
				continue;
			if (adj[x][y] <= adj[nx][ny])
				continue;

			pq.push({adj[nx][ny], nx, ny});
		}
	}

	cout << dp[N][M];
}