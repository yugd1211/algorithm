#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 맨처음 상태로 bfs 돌려서 벽이 아닌 맵에 대해서 그룹화 및 몇개인지 설정
// 벽인 곳에 대해서 상하좌우로 서로다른그룹들에 대해서 갯수를 더하고 + 1해줌

int N, M;

int board[1001][1001];
int res[1001][1001];
int vis[1001][1001];
int g[1001][1001];
vector<int> gc;

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
			if (board[i][j] != 0)
				continue;
			if (vis[i][j])
				continue;
			int cnt = 0;
			int group = gc.size();
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
				g[x][y] = group;

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
			gc.push_back(cnt);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 1)
			{
				int cnt = 1;
				vector<int> useGroup;
				for (int k = 0; k < 4; k++)
				{
					int nx = dx[k] + i;
					int ny = dy[k] + j;

					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
						continue;

					if (board[nx][ny] == 0 && find(useGroup.begin(), useGroup.end(), g[nx][ny]) == useGroup.end())
					{
						cnt += gc[g[nx][ny]];
						useGroup.push_back(g[nx][ny]);
					}
				}
				res[i][j] = cnt % 10;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << res[i][j];
		cout << "\n";
	}
}