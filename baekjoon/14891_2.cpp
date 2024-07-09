#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
#define RIGHT 2
#define LEFT 6

deque<int> gear[4];
int vis[4];
int K;

void clear_vis()
{
	fill(vis, vis + 4, 0);
}

void rotate_gear(int n, int dir)
{
	if (dir == 1)
	{
		gear[n].push_front(gear[n].back());
		gear[n].pop_back();
	}
	else
	{
		gear[n].push_back(gear[n].front());
		gear[n].pop_front();
	}
}

void func(int g, int dir)
{
	if (vis[g])
		return;
	vis[g] = 1;
	if (g == 0)
	{
		if (gear[0][RIGHT] != gear[1][LEFT] && !vis[1])
			func(1, dir * -1);
	}
	if (g == 1)
	{
		if (gear[1][LEFT] != gear[0][RIGHT] && !vis[0])
			func(0, dir * -1);
		if (gear[1][RIGHT] != gear[2][LEFT] && !vis[2])
			func(2, dir * -1);
	}
	if (g == 2)
	{
		if (gear[2][LEFT] != gear[1][RIGHT] && !vis[1])
			func(1, dir * -1);
		if (gear[2][RIGHT] != gear[3][LEFT] && !vis[3])
			func(3, dir * -1);
	}
	if (g == 3)
	{
		if (gear[3][LEFT] != gear[2][RIGHT] && !vis[2])
			func(2, dir * -1);
	}
	rotate_gear(g, dir);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char n;
			cin >> n;
			gear[i].push_back(n - '0');
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int g, d; // 몇번째 톱니, 방향 : 1 = 시계, -1 = 반시계
		cin >> g >> d;
		clear_vis();
		func(g - 1, d);
	}

	cout << (gear[0][0] == 1 ? 1 : 0) +
				(gear[1][0] == 1 ? 2 : 0) +
				(gear[2][0] == 1 ? 4 : 0) +
				(gear[3][0] == 1 ? 8 : 0);
}