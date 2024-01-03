#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;

int M, N, K;
int board[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin >> M >> N >> K;
    while (K--)
    {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        for (int i = ly; i < ry; i++)
        {
            for (int j = lx; j < rx; j++)
            {
                board[i][j] = -1;
            }
        }
    }
    queue<pair<int, int>> q;
    vector<int> vec;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                int cnt = 1;
                q.push({i, j});
                while (!q.empty())
                {
                    int x = q.front().X;
                    int y = q.front().Y;
                    q.pop();
                    if (x < 0 || y < 0 || x >= M || y >= N)
                        continue;
                    if (board[x][y])
                        continue;
                    board[x][y] = cnt++;
                    for (int i = 0; i < 4; i++)
                        q.push({x + dx[i], y + dy[i]});
                }
                vec.push_back(cnt);
            }
        }
    }
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] - 1 << " ";
}
