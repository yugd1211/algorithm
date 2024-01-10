#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void printBoard();
void printVis(int n);
bool checkVis(int x, int y, int crush);

int N, M, K;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[1001][1001];
int vis[1001][1001][11];

int main()
{
    queue<tuple<int, int, int>> q;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (int i = 0; i < 11; i++)
        vis[0][0][i] = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    q.push({0, 0, 0});
    while (!q.empty())
    {
        int x, y, crush;
        tie(x, y, crush) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
        {
            cout << vis[x][y][crush];

            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;
            if (checkVis(x + dx[i], y + dy[i], crush))
                continue;
            vis[x + dx[i]][y + dy[i]][crush] = vis[x][y][crush] + 1;
            q.push({x + dx[i], y + dy[i], crush});
        }
        if (crush >= K)
            continue;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M)
                continue;
            if (!board[x + dx[i]][y + dy[i]])
                continue;
            if (checkVis(x + dx[i], y + dy[i], crush + 1))
                continue;
            vis[x + dx[i]][y + dy[i]][crush + 1] = vis[x][y][crush] + 1;
            q.push({x + dx[i], y + dy[i], crush + 1});
        }
    }
    cout << -1;
}

//
//
void printBoard()
{
    cout << "============board============\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 111111111)
                cout << "x ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
void printVis(int n)
{
    cout << "============ " << n << " ============\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vis[i][j][n] == 111111111)
                cout << "x ";
            else
                cout << vis[i][j][n] << " ";
        }
        cout << "\n";
    }
}

bool checkVis(int x, int y, int crush)
{
    for (int i = 0; i <= crush; i++)
    {
        if (vis[x][y][i] && vis[x][y][i] <= vis[x][y][crush])
        {
            vis[x][y][crush] = vis[x][y][i];
            return 1;
        }
    }
    return 0;
}