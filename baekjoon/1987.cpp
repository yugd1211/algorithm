#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C;
int ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char board[21][21];
bool vis[300];

void input()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];
}

void dfs(int x, int y, int cnt)
{
	ans = max(ans, cnt);
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
			continue;
		if (vis[board[nx][ny]])
			continue;

		vis[board[nx][ny]] = true;
		dfs(nx, ny, cnt + 1);
		vis[board[nx][ny]] = false;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	vis[board[0][0]] = true;
	dfs(0, 0, 1);
	cout << ans;
}