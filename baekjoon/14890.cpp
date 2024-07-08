#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
int N, L; // <= 100

int board[101][101];
int vis[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void clear_vis()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
	}
}

bool check_ramp(int x, int y, int dir)
{
	int num = board[x][y];
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;
	for (int i = 0; i < L; i++)
	{
		int nx = x + (dx[dir] * i);
		int ny = y + (dy[dir] * i);
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			return false;
		if (num != board[nx][ny])
			return false;
		if (vis[nx][ny])
			return false;
		vis[nx][ny] = 1;
	}
	return true;
}

bool check_horiz_road(int index)
{
	bool flag = 1;
	int num = board[index][0];
	clear_vis();
	for (int i = 1; i < N; i++)
	{
		if (num == board[index][i])
			continue;
		else if (abs(num - board[index][i]) > 1)
			return false;
		else
		{
			int x = index;
			int y;
			int dir;
			if (num - board[index][i] == 1)
			{
				y = i;
				dir = RIGHT;
			}
			else
			{
				y = i - 1;
				dir = LEFT;
			}
			if (!check_ramp(x, y, dir))
				return false;
		}
		num = board[index][i];
	}

	return true;
}

bool check_virt_road(int index)
{
	bool flag = 1;
	int num = board[0][index];
	clear_vis();
	for (int i = 1; i < N; i++)
	{
		if (num == board[i][index])
			continue;
		else if (abs(num - board[i][index]) > 1)
			return false;
		else
		{
			int x;
			int y = index;
			int dir;
			if (num - board[i][index] == 1)
			{
				x = i;
				dir = DOWN;
			}
			else
			{
				x = i - 1;
				dir = UP;
			}
			if (!check_ramp(x, y, dir))
				return false;
		}
		num = board[i][index];
	}
	return true;
}

int main()
{
	int ans = 0;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	for (int i = 0; i < N; i++)
		ans += check_horiz_road(i);
	for (int i = 0; i < N; i++)
		ans += check_virt_road(i);
	cout << ans;
}