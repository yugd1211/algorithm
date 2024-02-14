#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int origin[101][101];
int board[101][101];

void printBoard()
{
    cout << "=================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == -1)
                cout << "x ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void copyBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = origin[i][j];
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> origin[i][j];
    int ans = 0;
    queue<pair<int, int>> q;
    for (int h = 0; h < 101; h++)
    {
        int cnt = 0;
        copyBoard();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] > h)
                {
                    cnt++;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (x < 0 || y < 0 || x >= N || y >= N)
                            continue;
                        if (board[x][y] <= h)
                            continue;
                        board[x][y] = -1;
                        for (int i = 0; i < 4; i++)
                            q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}