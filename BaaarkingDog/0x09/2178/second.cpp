// 
// 다른 사람의 풀이를 보니 문제 해결법은 비슷하다.
// 하지만 queue<pair<pair<int, int>, int> >Q; 에서 나는 cnt까지 Q에 담아주는데
// Q에 포함하지 않고 cnt 배열을 만들어서 담아주는 방식으로 진행한다.
// 위처럼 바꾸게 되면 1/3의 메모리를 확보하게 되기 때문에 시도해본다.
// 위처럼 바꿔서 통과함

#include <iostream>
#include <queue>
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool board[101][101];
int dist[101][101];
using namespace std;
int main()
{
    queue<pair<int, int> > Q;
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
    Q.push(make_pair(0, 0));
    dist[0][0] = 1;
    while (!Q.empty())
    {
        pair<int, int>curr = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + curr.X;
            int ny = dy[i] + curr.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] == 0 || dist[nx][ny] > 0)
                continue;
            dist[nx][ny] = dist[curr.X][curr.Y] + 1;
            Q.push(make_pair(nx, ny));
        }
        if (curr.X == N - 1 && curr.Y == M - 1)
        {
            cout << dist[curr.X][curr.Y];
            return 0;
        }
    }
}