#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int L, R, C;
// 층수
// 행
// 열

// # = 벽
// . = 길
// S = 현재 위치
// E = 출구

int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
queue<tuple<int, int, int>> q;

char board[31][31][31];
int vis[31][31][31];

void clearVis()
{
    for (int i = 0; i < 31; i++)
        for (int j = 0; j < 31; j++)
            for (int k = 0; k < 31; k++)
                vis[i][j][k] = -1;
}

void clearQueue()
{
    queue<tuple<int, int, int>> empty;
    swap(q, empty);
}

void printBoard()
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                cout << board[i][j][k];
            }
            cout << "\n";
        }
    }
}

void printVis()
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (vis[i][j][k] == -1)
                    cout << "#";
                else
                    cout << vis[i][j][k];
            }
            cout << "\n";
        }
    }
}

void input()
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {
            for (int k = 0; k < C; k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 'S')
                {
                    q.push({i, j, k});
                    vis[i][j][k] = 0;
                }
            }
        }
    }
}

int main()
{
    while (1)
    {
        bool exitFlag = false;
        cin >> L >> R >> C;
        if (L == 0 && R == 0 && C == 0)
            break;
        clearVis();
        clearQueue();
        input();
        while (!q.empty())
        {

            int x, y, z;
            tie(x, y, z) = q.front();
            q.pop();
            if (board[x][y][z] == 'E')
            {
                exitFlag = 1;
                cout << "Escaped in " << vis[x][y][z] << " minute(s).\n";
                break;
            }
            for (int i = 0; i < 6; i++)
            {
                if (x + dx[i] < 0 || x + dx[i] >= L ||
                    y + dy[i] < 0 || y + dy[i] >= R ||
                    z + dz[i] < 0 || z + dz[i] >= C)
                    continue;
                if (vis[x + dx[i]][y + dy[i]][z + dz[i]] != -1)
                    continue;
                if (board[x + dx[i]][y + dy[i]][z + dz[i]] != '#')
                {
                    q.push({x + dx[i], y + dy[i], z + dz[i]});
                    vis[x + dx[i]][y + dy[i]][z + dz[i]] = vis[x][y][z] + 1;
                }
            }
        }
        if (!exitFlag)
            cout << "Trapped!\n";
    }
}