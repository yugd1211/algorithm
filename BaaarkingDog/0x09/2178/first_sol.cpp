// 
// 메모리 초과
// 메모리가 192 MB 까지 가능한데
// queue에 push한 숫자가 그 이상인건가..

#include <iostream>
#include <queue>
#define X first
#define Y second
#define bd first
#define cnt second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool board[101][101];
bool vis[101][101];
using namespace std;
int main()
{
    queue<pair<pair<int, int>, int> >Q;
    int N, M;
    int minCnt = 0;
    cin >> N; cin >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    Q.push(make_pair(make_pair(0, 0), 1));
    vis[0][0] = 1;
    while (!Q.empty())
    {
        pair<pair<int, int>, int> curr = Q.front();
        Q.pop();
        if (curr.bd.X == N - 1 && curr.bd.Y == M - 1)
        {
            cout << curr.cnt;
            return 0;
        }
        vis[curr.bd.X][curr.bd.Y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + curr.bd.X;
            int ny = dy[i] + curr.bd.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                continue;
            Q.push(make_pair(make_pair(nx, ny), curr.cnt + 1));
        }
    }
}