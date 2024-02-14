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

// vis에 밤낮이 설정되지 않으니까
int vis[1001][1001][11];

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
    q.push({0, 0, 0, 0});
    for (int i = 0; i < 11; i++)
        vis[0][0][i] = 1;
    while (!q.empty())
    {
        int x, y, crush;
        bool sun;
        tie(x, y, crush, sun) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 ||
                x + dx[i] >= N || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;

            if (isVisited(x + dx[i], y + dy[i], crush) && vis[x + dx[i]][y + dy[i]][crush] <= vis[x][y][crush] + 1)
                continue;
            if (!vis[x + dx[i]][y + dy[i]][crush] || vis[x + dx[i]][y + dy[i]][crush] > vis[x][y][crush] + 1)
            {
                vis[x + dx[i]][y + dy[i]][crush] = vis[x][y][crush] + 1;
                q.push({x + dx[i], y + dy[i], crush, !sun});
            }
        }

        if (crush >= K)
            continue;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 ||
                x + dx[i] >= N || y + dy[i] >= M)
                continue;
            if (!board[x + dx[i]][y + dy[i]])
                continue;
            if (sun == MORNING)
            {
                if (isVisited(x + dx[i], y + dy[i], crush + 1) && vis[x + dx[i]][y + dy[i]][crush + 1] <= vis[x][y][crush] + 1)
                    continue;
                if (!vis[x + dx[i]][y + dy[i]][crush + 1] || vis[x + dx[i]][y + dy[i]][crush + 1] > vis[x][y][crush] + 1)
                {
                    vis[x + dx[i]][y + dy[i]][crush + 1] = vis[x][y][crush] + 1;
                    q.push({x + dx[i], y + dy[i], crush + 1, !sun});
                }
            }
            else
            {
                if (isVisited(x + dx[i], y + dy[i], crush + 1) && vis[x + dx[i]][y + dy[i]][crush + 1] <= vis[x][y][crush] + 2)
                    continue;
                if (!vis[x + dx[i]][y + dy[i]][crush + 1] || vis[x + dx[i]][y + dy[i]][crush + 1] > vis[x][y][crush] + 2)
                {
                    vis[x + dx[i]][y + dy[i]][crush + 1] = vis[x][y][crush] + 2;
                    q.push({x + dx[i], y + dy[i], crush + 1, sun});
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= K; i++)
    {
        if (vis[N - 1][M - 1][i])
            ans = min(ans, vis[N - 1][M - 1][i]);
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;
}

bool isVisited(int x, int y, int crush)
{
    int n = INF;
    for (int i = 0; i <= crush; i++)
    {
        if (vis[x][y][i])
        {
            n = min(n, vis[x][y][i]);
        }
    }
    if (n == INF)
        return 0;
    vis[x][y][crush] = n;
    return 1;
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
    for (int crush = 2; crush <= K; crush++)
    {
        cout << "=================== " << crush << " ==================\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << vis[i][j][crush];
            }
            cout << "\n";
        }
    }
}