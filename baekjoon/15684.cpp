#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
#define HEIGHT_MAX 32
#define WIDTH_MAX 12

int N, M, H;
int ans = 1000000;
array<array<int, WIDTH_MAX>, HEIGHT_MAX> board;

void clear_board(array<array<int, WIDTH_MAX>, HEIGHT_MAX> board)
{
	for (int i = 0; i < WIDTH_MAX; i++)
	{
		for (int j = 0; j < HEIGHT_MAX; j++)
			board[i][j] = 0;
	}
}

bool check_line(int line, array<array<int, WIDTH_MAX>, HEIGHT_MAX> board)
{
	int curr = line;
	for (int i = 1; i <= H; i++)
	{
		if (board[i][curr])
			curr++;
		else if (board[i][curr - 1])
			curr--;
	}
	if (curr != line)
		return false;
	return true;
}

bool check_all_line(array<array<int, WIDTH_MAX>, HEIGHT_MAX> board)
{
	for (int i = 1; i <= N; i++)
	{
		if (!check_line(i, board))
			return false;
	}
	return true;
}

void dfs(int x, int y, int cnt, array<array<int, WIDTH_MAX>, HEIGHT_MAX> board)
{
	if (check_all_line(board))
	{
		ans = min(ans, cnt);
		if (ans == 0)
		{
			cout << 0;
			exit(0);
		}
		return;
	}
	if (cnt >= 3)
		return;
	for (int i = x; i <= H; i++)
	{
		for (int j = i == x ? y : 1; j < N; j++)
		{
			if (board[i][j] || board[i][j - 1])
				continue;
			if (!board[i][j + 1])
			{
				array<array<int, WIDTH_MAX>, HEIGHT_MAX> tmp(board);
				tmp[i][j] = 1;
				dfs(i, j + 1, cnt + 1, tmp);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M >> H;
	clear_board(board);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}
	dfs(1, 1, 0, board);

	cout << (ans <= 3 ? ans : -1);
}
