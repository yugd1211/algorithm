#include <iostream>
#include <algorithm>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[301][301];
int T;

int dx[8] = {1, 2, -1, 2, 1, -2, -1, -2};
int dy[8] = {2, 1, 2, -1, -2, 1, -2, -1};

void clearBoard()
{
    for (int i = 0; i < 301; i++)
        for (int j = 0; j < 301; j++)
            board[i][j] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        queue<pair<int, int>> q;
        int size, curr[2], goal[2];

        clearBoard();
        cin >> size >> curr[0] >> curr[1] >> goal[0] >> goal[1];
        q.push({curr[0], curr[1]});
        board[curr[0]][curr[1]] = 1;
        while (!q.empty())
        {
            int x = q.front().X;
            int y = q.front().Y;
            q.pop();

            if (x == goal[0] && y == goal[1])
            {
                cout << board[x][y] - 1 << "\n";
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                if (x + dx[i] < 0 || x + dx[i] >= size ||
                    y + dy[i] < 0 || y + dy[i] >= size)
                    continue;
                if (board[x + dx[i]][y + dy[i]])
                    continue;
                board[x + dx[i]][y + dy[i]] = board[x][y] + 1;
                q.push({x + dx[i], y + dy[i]});
            }
        }
    }
}