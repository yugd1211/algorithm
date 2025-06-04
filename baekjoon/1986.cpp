#include <iostream>
using namespace std;

#define Q 100
#define K 101
#define P 102

int N, M;
int board[1001][1001];

int kx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int ky[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int qdx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int qdy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void queenMove(int x, int y)
{
	for (int dir = 0; dir < 8; dir++)
	{
		int nx = x, ny = y;
		while (true)
		{
			nx += qdx[dir];
			ny += qdy[dir];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M)
				break;
			if (board[nx][ny] >= Q)
				break;
			if (board[nx][ny] == 0)
				board[nx][ny] = 1;
		}
	}
}

void knightMove(int x, int y)
{
	for (int i = 0; i < 8; i++)
	{
		int nx = x + kx[i];
		int ny = y + ky[i];
		if (nx <= 0 || ny <= 0 || nx > N || ny > M)
			continue;
		if (board[nx][ny] == 0)
			board[nx][ny] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	// 입력
	for (int type = 0; type < 3; type++)
	{
		int count;
		cin >> count;
		for (int i = 0; i < count; i++)
		{
			int x, y;
			cin >> x >> y;
			board[x][y] = Q + type;
		}
	}

	// 기물 이동
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= M; y++)
		{
			if (board[x][y] == Q)
				queenMove(x, y);
			else if (board[x][y] == K)
				knightMove(x, y);
		}
	}

	// 이동 못하는 좌표 계산
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (board[i][j] == 0)
				answer++;
		}
	}
	cout << answer;
}
