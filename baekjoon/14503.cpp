#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int ans = 0;
int board[51][51];
int vis[51][51];

int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

void print_board()
{
	cout << "=================board===========\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

// 0 = 북, 1 = 동, 2 = 남, 3 = 서
void move_robot(int x, int y, int d)
{
	if (board[x][y] == 0 && !vis[x][y])
	{
		vis[x][y] = 1;
		board[x][y] = 2;
		print_board();

		ans++;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (board[nx][ny] != 0 || vis[nx][ny])
			continue;
		move_robot(nx, ny, d);
		return;
		--d == -1 ? 3 : d;
	}
	int nx = x + dirX[(d + 2) % 4];
	int ny = y + dirY[(d + 2) % 4];
	if (nx < 0 || ny < 0 || nx >= N || ny >= M)
		return;
	if (board[nx][ny] == 1)
		return;
	move_robot(nx, ny, d);
}

int main()
{

	cin.tie(0);
	ios::sync_with_stdio(0);
	int r, c, d;
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	move_robot(r, c, d);
	print_board();
	cout << ans;
}