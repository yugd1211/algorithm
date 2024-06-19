#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int board[501][501];
int ret = 0;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

bool check(vector<pair<int, int>> log, pair<int, int> next)
{
	for (int i = 0; i < log.size(); i++)
	{
		if (log[i].first == next.first && log[i].second == next.second)
			return false;
	}
	return true;
}

void dfs(int depth, int count, int x, int y, vector<pair<int, int>> log)
{
	count += board[x][y];
	if (depth == 3)
	{
		ret = max(ret, count);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (x + dirX[i] < 0 || y + dirY[i] < 0 || x + dirX[i] >= N || y + dirY[i] >= M)
			continue;
		if (!check(log, {x + dirX[i], y + dirY[i]}))
			continue;
		log.push_back({x + dirX[i], y + dirY[i]});
		dfs(depth + 1, count, x + dirX[i], y + dirY[i], log);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			vector<pair<int, int>> vec;
			vec.push_back({i, j});
			dfs(0, 0, i, j, vec);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 1 < N && j + 2 < M)
				ret = max(ret, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1]);
			if (i + 2 < N && j + 1 < M)
				ret = max(ret, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1]);
			if (i + 1 < N && j - 1 >= 0 && j + 1 < M)
				ret = max(ret, board[i][j] + board[i + 1][j] + board[i + 1][j - 1] + board[i + 1][j + 1]);
			if (i - 1 >= 0 && i + 1 < N && j + 1 < M)
				ret = max(ret, board[i][j] + board[i][j + 1] + board[i - 1][j + 1] + board[i + 1][j + 1]);
		}
	}
	cout << ret;
}