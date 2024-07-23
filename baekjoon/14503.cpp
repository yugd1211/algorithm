#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define NON_CLEAR 0
#define WALL 1
#define CLEAR 2

int N, M;
int r, c, d;
int ans;
int cnt = 2;
int board[51][51];
int dirX[4] = {-1, 0, 1, 0};
int dirY[4] = {0, 1, 0, -1};

void input()
{
	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
}

void print_board()
{
	cout << "=================board===========\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

bool is_clearable(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dirX[i];
		int ny = y + dirY[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (board[nx][ny] != NON_CLEAR)
			continue;
		return true;
	}
	return false;
}

bool is_clear_curr(int x, int y)
{
	if (board[x][y] == NON_CLEAR)
		return true;
	else
		return false;
}

// 0 = 북, 1 = 동, 2 = 남, 3 = 서
bool move(int &x, int &y, int &d)
{
	if (is_clear_curr(x, y))
	{
		board[x][y] = cnt++;
		ans++;
	}
	if (is_clearable(x, y))
	{
		for (int i = 0; i < 4; i++)
		{
			d--;
			if (d == -1)
				d = 3;
			int nx = x + dirX[d];
			int ny = y + dirY[d];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (board[nx][ny] != NON_CLEAR)
				continue;
			x = nx;
			y = ny;
			break;
		}
		return true;
	}
	else
	{
		int back_dir = (d + 2) % 4;
		int nx = x + dirX[back_dir];
		int ny = y + dirY[back_dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			return false;
		if (board[nx][ny] == WALL)
			return false;
		x = nx;
		y = ny;
		return true;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	while (move(r, c, d))
		;
	cout << ans;
}