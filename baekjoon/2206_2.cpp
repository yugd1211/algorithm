#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 이전에 board를 공유해서 생긴 문제라고 판단하고,
// 재귀를 통해 board를 복사하고 그 뒤에 행위를 진행하는식으로 진행하려한다.
// 재귀가 쉽지 않은게 최소수치를 return받기가 쉽지 않다.
// 그리고 1000x1000이라 스택오버플로우가 발생할 확률이 크다.

int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// x, y, isCrush

void printBoard(int board[1001][1001])
{
    cout << "=====================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == -1)
                cout << 'x';
            else
                cout << board[i][j];
        }
        cout << "\n";
    }
}

int bfs(int board[1001][1001], int x, int y, int cnt, int isCrush)
{
    board[x][y] = cnt;
    if (x == N - 1 && y == M - 1)
        return cnt;
    for (int i = 0; i < 4; i++)
    {
        if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
            continue;
        if (board[x + dx[i]][y + dy[i]])
            continue;
        bfs(board, x + dx[i], y + dy[i], cnt + 1, isCrush);
    }
    if (!isCrush)
    {
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]] > 0)
                continue;
            bfs(board, x + dx[i], y + dy[i], cnt + 1, 1);
        }
    }
    return cnt;
}

int main()
{
    queue<tuple<int, int, bool>> q;

    cin >> N >> M;
    int board[1001][1001];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char n;
            cin >> n;
            if (n == '1')
                board[i][j] = -1;
            else
                board[i][j] = 0;
        }
    }
    q.push({0, 0, 0});
    board[0][0] = 1;
    cout << bfs(board, 0, 0, 1, 0);
    // printBoard(board);

    // if (board[N - 1][M - 1])
    //     cout << board[N - 1][M - 1];
    // else
    //     cout << -1;
}