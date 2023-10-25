#include <iostream>
#include <queue>
#include <tuple>
#define X 0
#define Y 1
#define isMen 2
#define fire 0
#define men 1

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
char board[1002][1002];
int dist[1002][1002] = {};

using namespace std;
int main()
{
    queue<tuple <int, int, bool> >Q;

    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'F')
                Q.push(make_tuple(i, j, fire));
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'J')
                Q.push(make_tuple(i, j, men));
        }
    }
    while (!Q.empty())
    {
        tuple <int, int, bool> curr = Q.front();
        Q.pop();
        if (get<isMen>(curr) == men && (get<X>(curr) == 0 || get<Y>(curr) == 0 || get<X>(curr) == N - 1 || get<Y>(curr) == M - 1))
        {
            cout << dist[get<X>(curr)][get<Y>(curr)] + 1;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int cx = get<X>(curr) + dx[i];
            int cy = get<Y>(curr) + dy[i];
            if (cx < 0 || cy < 0 || cx >= N || cy >= M)
                continue;
            else if (board[cx][cy] == '#')
                continue;
            else if (get<isMen>(curr) == men)
            {
                if (board[cx][cy] == '.' && dist[cx][cy] == 0)
                {
                    dist[cx][cy] = dist[get<X>(curr)][get<Y>(curr)] + 1;
                    Q.push(make_tuple(cx, cy, men));
                }
                // if (cx == 0 || cy == 0 || cx == N - 1 || cy == M - 1)
                // {
                //     cout << dist[cx][cy] + 1;
                //     return 0;
                // }
            }
            else if (get<isMen>(curr) == fire && board[cx][cy] != 'F')
            {
                board[cx][cy] = 'F';
                Q.push(make_tuple(cx, cy, fire));
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}