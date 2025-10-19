#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 시간초과
// 모든 정점에 대해서 bfs를 실행하다 보니 (N x M)^2으로 시간초과 발생

int N, M;

int board[1001][1001];
int res[1001][1001];
int vis[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;

void clearVis()
{
	for (int i = 0; i < 1001; i++)
	{
		fill(vis[i], vis[i] + 1001, 0);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
				continue;
			clearVis();
			int cnt = 0;
			q.push({i, j});
			while (!q.empty())
			{
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				if (vis[x][y])
					continue;
				cnt++;
				vis[x][y] = 1;

				for (int i = 0; i < 4; i++)
				{
					int nx = dx[i] + x;
					int ny = dy[i] + y;
					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
						continue;
					if (board[nx][ny])
						continue;
					if (vis[nx][ny])
						continue;
					q.push({nx, ny});
				}
			}
			res[i][j] = cnt % 10;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << res[i][j];
		cout << "\n";
	}
}