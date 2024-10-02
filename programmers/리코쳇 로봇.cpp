#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int vis[101][101];
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// cost, x, y
queue<tuple<int, int, int>> q;

// . : 빈공간
// D : 장애물
// R : 시작위치
// G : 종료 위치

void input(const vector<string> &board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 'R')
			{
				q.push({1, i, j});
				vis[i][j] = 1;
			}
		}
	}
}

int solution(vector<string> board)
{
	input(board);
	N = board.size();
	M = board[0].size();
	while (!q.empty())
	{
		int cost, x, y;
		tie(cost, x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[i].size() && board[nx][ny] != 'D')
			{
				nx += dx[i];
				ny += dy[i];
			}
			nx -= dx[i];
			ny -= dy[i];
			if (vis[nx][ny])
				continue;
			if (board[nx][ny] == 'G')
				return cost;
			vis[nx][ny] = cost + 1;
			q.push({cost + 1, nx, ny});
		}
	}
	return -1;
}