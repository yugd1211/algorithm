#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, M, N, K;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int vis[51][51];
int board[51][51];

int bfs(int x, int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return 0;
    if (vis[x][y] || !board[x][y])
        return 0;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
        bfs(x + dx[i], y + dy[i]);
    return 1;
}

void printBoard()
{
    cout << "============board============\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j];
        cout << "\n";
    }
}
void printVis()
{
    cout << "============vis============\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << vis[i][j];
        cout << "\n";
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        int ans = 0;
        for (int i = 0; i < 51; i++)
            fill(board[i], board[i] + 51, 0);
        for (int i = 0; i < 51; i++)
            fill(vis[i], vis[i] + 51, 0);
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++)
        {
            int a, b;
            cin >> a >> b;
            board[b][a] = 1;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (bfs(i, j))
                    ans++;
            }
        }
        // printBoard();
        // printVis();
        cout << ans << "\n";
    }
}