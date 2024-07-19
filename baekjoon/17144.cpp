#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int up_dx[4] = {0, -1, 0, 1};
int up_dy[4] = {1, 0, -1, 0};

int down_dx[4] = {0, 1, 0, -1};
int down_dy[4] = {1, 0, -1, 0};

int R, C, T;
int A[51][51];
int B[51][51];
vector<pair<int, int>> air;
queue<pair<int, int>> dust;

void print_A()
{
	cout << "==========AAAAAAAAAAAA============\n";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << A[i][j] << ' ';
		cout << "\n";
	}
}

void print_B()
{
	cout << "==========BBBBBBBBBBBB============\n";
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cout << B[i][j] << ' ';
		cout << "\n";
	}
}

// 순서
// 먼지가 확산 상하 좌우로 확산
// 공기청정기 바람 가동

void input()
{
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == -1)
			{
				B[i][j] = -1;
				air.push_back({i, j});
			}
			else if (A[i][j])
				dust.push({i, j});
		}
	}
}

int ans_calc()
{
	int ans = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] <= 0)
				continue;
			ans += A[i][j];
		}
	}
	return ans;
}

void copy_B_to_A()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] != -1)
				A[i][j] = B[i][j];
			else
				cout << B[i][j];
		}
		// copy(B[i], B[i] + C, A[i]);
	}
}

void clear_B()
{
	for (int i = 0; i <= R; i++)
	{
		for (int j = 0; j <= C; j++)
			B[i][j] = 0;
	}
}

void dust_diffusion()
{
	while (!dust.empty())
	{
		int x, y;
		tie(x, y) = dust.front();
		dust.pop();
		int division_cnt = 0;
		int divided = A[x][y] / 5;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= R || ny >= C)
				continue;
			if (A[nx][ny] == -1)
				continue;
			division_cnt++;
			B[nx][ny] += divided;
		}
		B[x][y] += A[x][y] - (divided * division_cnt);
	}
}

void air_clear()
{
	int x, y;
	int dir = 0;
	tie(x, y) = air[0];
	int prev_val;

	prev_val = 0;
	while (1)
	{
		int nx = x + up_dx[dir];
		int ny = y + up_dy[dir];
		// cout << "next = " << A[nx][ny] << ", x = " << x << ", y = " << y << ", nx = " << nx << ", ny = " << ny << "\n";
		//  cout << "up_dx[dir] = " << up_dx[dir] << ", up_dy[dir] = " << up_dy[dir] << "\n";
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
		{
			dir++;
			dir = dir % 4;
			continue;
		}
		if (A[nx][ny] == -1)
			break;
		if (A[x][y] != -1)
		{
			int tmp = A[x][y];
			A[x][y] = prev_val;
			prev_val = tmp;
		}
		x = nx;
		y = ny;
	}

	tie(x, y) = air[1];
	dir = 0;
	prev_val = 0;
	while (1)
	{
		int nx = x + down_dx[dir];
		int ny = y + down_dy[dir];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)
		{
			dir++;
			dir = dir % 4;
			continue;
		}
		if (A[nx][ny] == -1)
			break;
		if (A[x][y] != -1)
		{
			// cout << "b\n";
			int tmp = A[x][y];
			A[x][y] = prev_val;
			prev_val = tmp;
		}
		x = nx;
		y = ny;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	for (int i = 0; i < T; i++)
	{
		dust_diffusion();
		copy_B_to_A();
		clear_B();
		air_clear();
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (A[i][j] <= 0)
					continue;
				dust.push({i, j});
			}
		}
		print_A();
	}
	cout << ans_calc();
}
