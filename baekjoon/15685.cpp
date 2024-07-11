#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[102][102];
int N; // < 20

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

vector<int> dragon[12]; // 0 : 오른쪽방향기준

void dragon_init()
{
	dragon[0].push_back(0);
	for (int i = 1; i <= 10; i++)
	{
		dragon[i] = dragon[i - 1];
		for (int j = dragon[i - 1].size() - 1; j >= 0; j--)
		{
			int n = (dragon[i - 1][j] + 1) % 4;
			dragon[i].push_back(n);
		}
	}
}

void draw(int x, int y, int d, int gen)
{
	board[x][y] = 1;
	for (int i = 0; i < dragon[gen].size(); i++)
	{
		int dir = (d + dragon[gen][i]) % 4;
		x += dx[dir];
		y += dy[dir];
		board[x][y] = 1;
	}
}

int check_square()
{
	int ret = 0;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (board[i][j] == 1 &&
				board[i + 1][j] == 1 &&
				board[i][j + 1] == 1 &&
				board[i + 1][j + 1] == 1)
				ret++;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	dragon_init();
	for (int i = 0; i < N; i++)
	{
		int x, y; // 좌표
		int d;	  // 방향
		int g;	  // 세대

		cin >> x >> y >> d >> g;
		draw(y, x, d, g);
	}
	cout << check_square();
}