#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

queue<tuple<int, int, int>> q;
int N,
	M;
int adj[101][71];
int vis[101][71];

void printVis()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << vis[i][j];
		}
		cout << "\n";
	}
}
void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> adj[i][j];
}

void bfs()
{
	while (!q.empty())
	{
		int c, x, y;
		tie(c, x, y) = q.front();
		q.pop();
		if (vis[x][y])
			continue;
		vis[x][y] = c;
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (vis[nx][ny])
				continue;
			if (adj[nx][ny] > adj[x][y])
				continue;
			q.push({c, nx, ny});
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	int cnt = 1;
	while (1)
	{
		int n = -1;
		int nx, ny;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (vis[i][j])
					continue;
				if (n < adj[i][j])
				{
					n = adj[i][j];
					nx = i;
					ny = j;
				}
			}
		}
		if (n == -1)
			break;
		q.push({cnt, nx, ny});
		bfs();
		cnt++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans = max(ans, vis[i][j]);
	cout << ans;
}