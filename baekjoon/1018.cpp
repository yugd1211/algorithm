#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
char board[50][50];

char WB[8][8] = {
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'};
char BW[8][8] = {
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'};

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	int ans;
	int res = 1000000;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int cnt_w = 0, cnt_b = 0;
			for (int x = 0; x < 8; x++)
			{
				for (int y = 0; y < 8; y++)
				{
					if (board[i + x][j + y] != BW[x][y])
						cnt_b++;
					if (board[i + x][j + y] != WB[x][y])
						cnt_w++;
				}
			}
			ans = min(cnt_b, cnt_w);
			if (ans <= res)
				res = ans;
		}
	}
	cout << res;
}
