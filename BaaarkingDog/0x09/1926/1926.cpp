#include <queue>
#include <iostream>
#define X first
#define Y second

bool board[501][501] = {};
bool vis[501][501] = {};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int n, m, cnt, maxSize;
int main()
{
    std::queue<std::pair<int, int> > Q;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int size = 0;
            if (board[i][j] == 1 && vis[i][j] == false)
            {
                vis[i][j] = true;
                Q.push(make_pair(i, j));
            }
            while (!Q.empty())
            {
                size++;
                pair<int, int> curr = Q.front(); Q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = curr.X + dx[k];
                    int ny = curr.Y + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (board[nx][ny] == false || vis[nx][ny] == true)
                        continue;
                    vis[nx][ny] = true;
                    Q.push(make_pair(nx, ny));
                }
            }
            if (size)
            {
                cnt++;
            }
            maxSize = max(maxSize, size);
        }
    }
    cout << cnt << "\n" << maxSize <<"\n";
}