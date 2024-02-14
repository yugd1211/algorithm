#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
#define MORNING 0
#define NIGHT 1

void printVis();
void printBoard();
bool isVisited(int x, int y, int crush);
using namespace std;
int board[1001][1001];

int vis[1001][1001][11][2];

// 낮 = false
// 밤 = true
queue<tuple<int, int, int, bool>> q;

// 세로, 가로, 벽 부술수 있는 횟수
int N, M, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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
    vis[0][0][0][0] = 1;
    q.push({0, 0, 0, 0});
    while (!q.empty())
    {
        int x, y, crush;
        bool sun;
        tie(x, y, crush, sun) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
        {
            cout << vis[x][y][crush][sun];
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 벽이 없을떄
            if (!board[nx][ny])
            {
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (vis[nx][ny][crush][!sun])
                    continue;
                vis[nx][ny][crush][!sun] = vis[x][y][crush][sun] + 1;
                q.push({nx, ny, crush, !sun});
            }
            // 벽이 있을떄
            else
            {
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (crush >= K)
                    continue;
                if (sun == MORNING)
                {
                    // 벽을 부술때랑 쉴때의 방문여부를 따로 확인해야되는데
                    // 한번에 확인하려고해서 시간 초과 발생했었음
                    if (vis[nx][ny][crush + 1][!sun])
                        continue;
                    vis[nx][ny][crush + 1][!sun] = vis[x][y][crush][sun] + 1;
                    q.push({nx, ny, crush + 1, !sun});
                }
                else
                {
                    if (vis[x][y][crush][!sun])
                        continue;
                    vis[x][y][crush][!sun] = vis[x][y][crush][sun] + 1;
                    q.push({x, y, crush, !sun});
                }
            }
        }
    }
    cout << -1;
}
void printBoard()
{
    cout << "======================board=======================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

void printVis()
{
    for (int sun = 0; sun < 2; sun++)
    {
        for (int crush = 0; crush <= K; crush++)
        {
            if (sun)
                cout << "=================== 밤 ";
            else
                cout << "=================== 낮 ";
            cout << crush << " ==================\n";
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    cout << vis[i][j][crush][sun];
                }
                cout << "\n";
            }
        }
    }
}