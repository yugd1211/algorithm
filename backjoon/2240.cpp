#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T, W;
int board[1001][2];
int vis[1001][2][31];

void printBoard()
{
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 현재 깊이, 어떤 나무밑에 있는지
    queue<tuple<int, bool, int>> q;
    cin >> T >> W;
    for (int i = 1; i <= T; i++)
    {
        int n;
        cin >> n;
        board[i][n - 1] = 1;
    }
    q.push({0, 0, 0});
    while (!q.empty())
    {
        int h, mc, w;
        tie(h, w, mc) = q.front();
        q.pop();
        if (h == T)
            continue;
        if (vis[h + 1][w][mc] < vis[h][w][mc] + 1 || vis[h + 1][w][mc] < vis[h][w][mc])
        {
            q.push({h + 1, w, mc});
            vis[h + 1][w][mc] = vis[h][w][mc];
            if (board[h + 1][w])
                vis[h + 1][w][mc]++;
        }
        if (mc >= W)
            continue;
        if (board[h + 1][w])
            continue;
        if (vis[h + 1][(w + 1) % 2][mc + 1] < vis[h][w][mc] + 1)
        {
            q.push({h + 1, (w + 1) % 2, mc + 1});
            vis[h + 1][(w + 1) % 2][mc + 1] = vis[h][w][mc] + 1;
        }
    }
    cout << "===================================================\n";
    int ans = 0;
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                // if (i == 1 && j == 1 && k == 1)
                // cout << "vis = " << vis[i][k][j];
                cout << vis[i][k][j] << " ";
                ans = max(ans, vis[i][k][j]);
            }
            cout << " ";
        }
        cout << "\n";
    }
    cout << ans;
}