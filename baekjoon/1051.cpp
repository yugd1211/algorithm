#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N, M;
int board[51][51];

int main()
{
	int conner = 1;
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < M; y++)
		{
			int size = conner;
			int nx = x + size;
			int ny = y + size;
			while (true)
			{
				if (nx >= N || ny >= M)
					break;
				if (board[x][y] == board[x][ny] &&
					board[x][y] == board[nx][y] &&
					board[x][y] == board[nx][ny])
				{
					conner = nx - x + 1;
				}
				nx++;
				ny++;
			}
		}
	}

	// 출력
	cout << conner * conner;
}