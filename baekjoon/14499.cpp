#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, X, Y;
int K;
pair<int, int> curr_point;
int map[21][21];
int dice[4][3] = {0};

int dirX[5] = {0, 0, 0, -1, 1};
int dirY[5] = {0, 1, -1, 0, 0};

void input_map()
{
	cin >> N >> M >> X >> Y >> K;
	curr_point = {X, Y};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

void move_dice(int num)
{
	if (num == 1)
	{
		int tmp = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = tmp;
	}
	else if (num == 2)
	{
		int tmp = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = tmp;
	}
	else if (num == 3)
	{
		int tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
	}
	else if (num == 4)
	{
		int tmp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = tmp;
	}
}

bool move_curr_point(int num)
{
	int x, y;
	tie(x, y) = curr_point;
	x += dirX[num];
	y += dirY[num];
	if (x >= N || y >= M || x < 0 || y < 0)
	{
		return false;
	}
	curr_point = make_pair(x, y);
	return true;
}

void change_down()
{
	if (map[curr_point.first][curr_point.second] == 0)
	{
		map[curr_point.first][curr_point.second] = dice[3][1];
	}
	else
	{
		dice[3][1] = map[curr_point.first][curr_point.second];
		map[curr_point.first][curr_point.second] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input_map();
	for (int i = 0; i < K; i++)
	{
		int n;
		cin >> n;
		if (!move_curr_point(n))
			continue;
		move_dice(n);
		change_down();
		cout << dice[1][1] << "\n";
	}
	return 0;
}
