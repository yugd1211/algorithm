#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[101][101];
bool vis[101][101];

int N;
int cnt = 0;

void dfs(int x, int y)
{
    if (vis[x][y])
        return;
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        if (dx[i] < 0 && dy[i] < 0 && dx[i] >= N && dy[i] >= N)
            continue;
        else
        {
            if (board[x + dx[i]][y + dy[i]] == board[x][y])
                dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    // 비적록색약
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = 0;
    cnt = 0;
    // 적록색약일떄는 그냥 R을 G로 바꾸고 dfs를 돌린다.
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'R')
                board[i][j] = 'G';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!vis[i][j])
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << " ";
}