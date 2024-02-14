#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제 풀이
// 이전 풀이로는 무조건 메모리 - 시간 초과가발생하기 때문에 뒤로 가는 경우를 최대한 줄여줘야한다.
// 특수한 경우(길이 뒤로 나이트 이동해야하는 경우같이)가 있기 때문에 뒤로 가는 행동자체를 없애는것은 안된다.
// 그래서 현재 노드의 나이트의 이동횟수가 보다 적은 족보에서 현재 위치까지 오는 거리가 더 적은 경우가 있으면 이로 대체하는 방식으로 진행해보려한다.

// 통과하기는 했지만 너무 오래걸리긴했다.
// 풀이 자체는 맞았지만 코드가 길어지고 수정의 수정을 반복하다보니 휴면에러가 많았고,
// 휴먼에러를 잡는 시간이 더 오래걸렸다....

int board[201][201];
int vis[201][201][31];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ndx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int ndy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// 나이트 이동횟수, 가로, 세로
int K, W, H;

// x, y, 나이트 이동 횟수
queue<tuple<int, int, int>> q;

bool checkPrev(int x, int y, int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (vis[x][y][i] && vis[x][y][i] <= vis[x][y][n])
        {
            vis[x][y][n] = vis[x][y][i];
            return 1;
        }
    }
    return 0;
}

void printVis(int n)
{
    cout << "=========  " << n << "  ===========\n";
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << vis[i][j][n] << " ";
        }
        cout << "\n";
    }
}

void printBoard()
{
    cout << "============board===========\n";
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 31; i++)
        vis[0][0][i] = 1;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        int x, y, nc;
        tie(x, y, nc) = q.front();
        q.pop();
        if (x == H - 1 && y == W - 1)
        {
            // printVis(0);
            // printVis(1);
            cout << vis[x][y][nc] - 1;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= H || y + dy[i] >= W)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;
            if (checkPrev(x + dx[i], y + dy[i], nc))
                continue;
            vis[x + dx[i]][y + dy[i]][nc] = vis[x][y][nc] + 1;
            q.push({x + dx[i], y + dy[i], nc});
        }
        if (nc >= K)
            continue;
        for (int i = 0; i < 8; i++)
        {
            if (x + ndx[i] < 0 || y + ndy[i] < 0 || x + ndx[i] >= H || y + ndy[i] >= W)
                continue;
            if (board[x + ndx[i]][y + ndy[i]])
                continue;
            if (checkPrev(x + ndx[i], y + ndy[i], nc + 1))
                continue;
            vis[x + ndx[i]][y + ndy[i]][nc + 1] = vis[x][y][nc] + 1;
            q.push({x + ndx[i], y + ndy[i], nc + 1});
        }
    }

    cout << -1;
}
