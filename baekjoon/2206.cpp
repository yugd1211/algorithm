#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 벽을 부수는걸 하나의 길로 취급하고 bool값으로 벽을 부쉈는지를 체크하고 안부쉈으면
// dx, dy로 부수고 지나가는 길로 queue에 담아주는 방식으로 진행했다
// 하지만 큰 모순이 board를 하나를 가지고 사용하니 부쉈을때 그 뒤로 bool값이 체크돼어
// 더이상은 부수지 않지만, 이 행위로 board판이 부숴진 상태가 된다.
// 그렇게 부수는 행위를 하지않던 노드들이 부숴진 길을 지나간다.

int N, M;
int board[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
// x, y, isCrush
queue<tuple<int, int, bool>> q;

void printBoard()
{
    cout << "=================\n";
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

int main()
{
    cin >> N >> M;
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
    while (!q.empty())
    {
        int x, y;
        bool isCrush;
        tie(x, y, isCrush) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;
            board[x + dx[i]][y + dy[i]] = board[x][y] + 1;
            q.push({x + dx[i], y + dy[i], isCrush});
        }
        if (!isCrush)
        {
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                    continue;
                if (board[x + dx[i]][y + dy[i]] > 0)
                    continue;
                board[x + dx[i]][y + dy[i]] = board[x][y] + 1;
                q.push({x + dx[i], y + dy[i], 1});
            }
        }
    }
    printBoard();

    if (board[N - 1][M - 1])
        cout << board[N - 1][M - 1];
    else
        cout << -1;
}