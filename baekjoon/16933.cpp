#include <algorithm>
#include <iostream>
#include <queue>
#define MORNING false
#define NIGHT true
using namespace std;

// 밤낮 배열을 두는것이 옳은가?
// 약간 불필요하게 복잡해지는것 같다.
// 우선순위 큐 혹은 덱을 이용하면 더 간편해질 코드가 밤낮을 확인하는 작업에서 꽤 힘들다.
// 밤낮인지 아닌지가 필요한 순간은 벽을 부수는 순간이다.
// 그 전까지는 밤낮 구분없이 움직일 수 있다.
// 벽을 부술때 밤이면 멈췄다 낮이 되면 ㅂ수고 이동하면된다.
// 우선순위 큐 혹은 덱을 이용하면 이게 편해지는게
// 밤이면 이동거리를 2로 늘리면 ...........우선순위 큐가 아니어도 될거 같기도하다.
// 그냥 해당 vis를 2칸 늘리고 진행하되 dfs같이 모든 행동이 끝나야 프로그램이 끝나게 되는데
// 이러면 시간이 너무 오래 걸릴거 같다.

bool checkVis(int x, int y, int crush);
void printBoard();
void printVis();
int N, M, K;
int board[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// false = 낮
// true = 밤
int vis[1001][1001][11][2];

// K 번 벽을 부술수있다.
// 첫이동은 낮
// 이동마다 밤낮이 바뀜
// 이동하지 않고 가만히 있을 수도있음
// 벽은 아침에만 부술수 있음

int main()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    queue<tuple<int, int, int, bool>> q;
    q.push({0, 0, 0, 0});
    for (int i = 0; i < 11; i++)
        vis[0][0][i][0] = 1;

    while (!q.empty())
    {
        int x, y, crush, sun;
        tie(x, y, crush, sun) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
        {
            cout << vis[x][y][crush][sun];
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;
            if (checkVis(x + dx[i], y + dy[i], crush))
                continue;
            printVis();
            // cout << "x = " << x << ", y = " << y << "\n";
            vis[x + dx[i]][y + dy[i]][crush][sun] = vis[x][y][i][sun] + 1;
            q.push({x + dx[i], y + dy[i], crush, (sun + 1) % 2});
        }
        // if (crush >= K)
        //     continue;
        // for (int i = 0; i < 4; i++)
        // {
        //     if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M)
        //         continue;
        //     if (!board[x][y])
        //         continue;
        //     if (checkVis(x + dx[i], y + dy[i], crush))
        //         continue;
        // }
    }
}

bool checkVis(int x, int y, int crush)
{
    for (int sun = 0; sun < 2; sun++)
    {
        for (int i = 0; i <= crush; i++)
        {
            if (vis[x][y][i][sun] && vis[x][y][i][sun] < vis[x][y][crush][sun])
            {
                vis[x][y][crush][sun] = vis[x][y][i][sun];
                return 1;
            }
        }
    }
    return 0;
}

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void printVis()
{
    for (int sun = 0; sun < 2; sun++)
    {
        for (int crush = 0; crush < K; crush++)
        {
            cout << "================= " << crush << " ===============\n";
            for (int x = 0; x < N; x++)
            {
                for (int y = 0; y < M; y++)
                {
                    cout << vis[x][y][crush][sun];
                }
                cout << "\n";
            }
        }
    }
}