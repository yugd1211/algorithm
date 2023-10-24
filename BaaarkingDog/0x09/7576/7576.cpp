#include <iostream>
#include <queue>
#define X first
#define Y second

int board[1001][1001]; //익은 토마토 1, 익지 않은 토마토 0, 토마토 없음 -1
int dist[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
using namespace std;
int main()
{
    queue<pair<int, int> > Q;
    cin >> M;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                Q.push(make_pair(i,j));
                dist[i][j] = 1;
            }
            else if (board[i][j] == -1)
                dist[i][j] = -1;
        }
    }
    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = curr.X + dx[i];
            int cy = curr.Y + dy[i];
            if (cx < 0 || cy < 0 || cx >= N || cy >= M)
                continue;
            if (board[cx][cy] != 0 || dist[cx][cy] != 0)
                continue;
            dist[cx][cy] = dist[curr.X][curr.Y] + 1;
            Q.push(make_pair(cx, cy));
        }
    }
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dist[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
            ret = max(ret, dist[i][j]);
        }
    }
    cout << ret - 1;
    return 0;
}