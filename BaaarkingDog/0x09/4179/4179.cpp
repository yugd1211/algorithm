#include <iostream>
#include <queue>
#include <tuple>
#define X 1
#define Y 2
#define isMen 2
#define fire 0
#define men 1

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
char board[1002][1002];
int dist[1002][1002];

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
            if (board[i][j] == 'J')
                Q.push(make_tuple(i, j, men));
            else if (board[i][j] == 'F')
                Q.push(make_tuple(i, j, fire));
        }
    }
    while (!Q.empty())
    {
        tuple <int, int, bool> curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = get<X>(curr) + dx[i];
            int cy = get<Y>(curr) + dy[i];
            if (cx < -1 || cy < -1 || cx >= N || cy >= M)
                continue;
            else if (board[cx][cy] == '#')
                continue;
            
        }
        // cout << get<X>(curr) << get<Y>(curr) << "\n";
    }
    cout << "IMPOSSIBLE";
    return 0;
}