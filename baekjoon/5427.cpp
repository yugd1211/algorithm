#include <iostream>
#include <algorithm>
#include <queue>
#define MAN 1
#define FIRE 0

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int T;
int board[1001][1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--)
    {
        queue<tuple<int, int, bool>> q;
        int w, h;
        bool isPossible = 0;
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char n;
                cin >> n;
                if (n == '.')
                    board[i][j] = 0;
                else if (n == '*')
                    board[i][j] = -1;
                else if (n == '#')
                    board[i][j] = -2;
                else if (n == '@')
                {
                    q.push({i, j, MAN});
                    board[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (board[i][j] == -1)
                    q.push({i, j, FIRE});
        while (!q.empty())
        {
            int x, y;
            bool isMan;
            tuple<int, int, int> t = q.front();
            tie(x, y, isMan) = t;
            q.pop();
            if (isMan == MAN && board[x][y] > 0 && (x == 0 || y == 0 || x == h - 1 || y == w - 1))
            {
                isPossible = 1;
                cout << board[x][y] << "\n";
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= h || y + dy[i] >= w)
                    continue;
                if (isMan == MAN)
                {
                    if (board[x + dx[i]][y + dy[i]] == 0)
                    {
                        board[x + dx[i]][y + dy[i]] = board[x][y] + 1;
                        q.push({x + dx[i], y + dy[i], MAN});
                    }
                }
                else
                {
                    if (board[x + dx[i]][y + dy[i]] == -2 ||
                        board[x + dx[i]][y + dy[i]] == -1)
                        continue;
                    board[x + dx[i]][y + dy[i]] = -1;
                    q.push({x + dx[i], y + dy[i], FIRE});
                }
            }
        }
        if (!isPossible)
            cout << "IMPOSSIBLE\n";
    }
}