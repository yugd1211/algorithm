#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// 문제 풀이
// 처음 board를 입력받고 bfs를 실행시켜서 각 섬별로 넘버링을 한다.
// 넘버링을 하는이유는 서로 각기 다른 섬에서 넘어갔는지를 확인하기 위해서
// dist를 dist[x][y][num]로 선언하는데 num은 몇번째 섬인지이고 담고자하는 변수는 해당 섬에서 현재 위치까지의 거리이다.
// 그렇기 때문에 섬에서의 최단 거리를 알기 위한 bfs를 실행하기 위한 queue또한 <x, y, n>으로 n은 몇번째 섬에서부터 시작했는지를 나타낸다.
// bfs의 종료조건은 4방향으로 search를 뻗어나가다 search하는 노드의 n(섬의 넘버)과 다음으로 이동하고자하는 곳의 n이 다를 떄이다.

// 풀고 나니 그렇게 까지 어려운 문제는 아니였지만 중간 중간 계속 코드를 고쳐썼다.
// 처음에는 dist와 queue를 2차배열로 선언해서 확인하다가 이렇게 하니 어떤 섬인지를 확인하지 못하고,
// 그렇게하고 보니 bfs의 종료 조건을 확인할때 다음방향의 섬이 몇번쨰인지는 알지만, search하는 노드가 몇번째 섬에서 파생됐는지를 알수가 없었다.
// 그래서 queue도 <x,y> 에서 <x,y,n>으로 바꾸게 되었다.
// 처음 간단하게 그려본 설계와는 많이 바뀌긴했지만, 비슷한 문제일때 3차배열 선언해야 된다는걸 오늘보다는 빨리 도달할 것 같다.

int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> q;
int board[101][101];
int dist[101][101][101];

void clearQueue()
{
    queue<pair<int, int>> tmp;
    swap(q, tmp);
}

int main()
{
    queue<tuple<int, int, int>> q2;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                board[i][j] = -1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != -1)
                continue;
            q.push({i, j});
            board[i][j] = ++cnt;
            while (!q.empty())
            {
                int x, y;
                tie(x, y) = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= N)
                        continue;
                    if (board[x + dx[i]][y + dy[i]] == -1)
                    {
                        board[x + dx[i]][y + dy[i]] = cnt;
                        q.push({x + dx[i], y + dy[i]});
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                q2.push({i, j, board[i][j]});
                dist[i][j][board[i][j]] = 1;
            }
        }
    }

    while (!q2.empty())
    {
        int x, y, n;
        tie(x, y, n) = q2.front();
        q2.pop();
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= N)
                continue;
            if (dist[x + dx[i]][y + dy[i]][n])
                continue;
            if (board[x + dx[i]][y + dy[i]] && board[x + dx[i]][y + dy[i]] != n)
            {
                cout << dist[x][y][n] - 1;
                return 0;
            }
            dist[x + dx[i]][y + dy[i]][n] = dist[x][y][n] + 1;
            q2.push({x + dx[i], y + dy[i], n});
        }
    }
}
