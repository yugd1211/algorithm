#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// H, N, M
int board[101][101][101];
bool vis[101][101][101];

int M, N, H;

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
queue<tuple<int, int, int>> que;

int main()
{
    int ans = 1;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                cin >> board[i][j][k];

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[i][j][k] == 1)
                {
                    vis[i][j][k] = 1;
                    que.push({i, j, k});
                }
            }
        }
    }

    int cnt = 0;
    while (!que.empty())
    {
        tuple<int, int, int> t = que.front();
        int x, y, z;
        que.pop();
        tie(x, y, z) = t;
        for (int i = 0; i < 6; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || z + dz[i] < 0 || x + dx[i] >= H || y + dy[i] >= N || z + dz[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]][z + dz[i]] == -1 || vis[x + dx[i]][y + dy[i]][z + dz[i]])
                continue;
            vis[x + dx[i]][y + dy[i]][z + dz[i]] = 1;
            board[x + dx[i]][y + dy[i]][z + dz[i]] = board[x][y][z] + 1;
            que.push({x + dx[i], y + dy[i], z + dz[i]});
        }
    }

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (board[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                ans = max(ans, board[i][j][k]);
            }
        }
    }
    cout << ans - 1;
}
