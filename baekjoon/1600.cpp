#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제 풀이
// vis를 [x][y][k]로 나이트의 행동횟수만큼 배열을 만들어준다.
// bfs를 0,0 부터 h , w에 도달할때까지 상하좌우, 나이트의 횟수까지 8번씩 search를 넓혀나간다.
// 문제는 이렇게 모든 경우의 수를 찾다보면 뒤로 가는 것까지 포함해서 (200*200*31)^2이 되버린다.
// 그렇기 때문에 메모리 초과발생

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

bool checkVis(int x, int y, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vis[x][y][i] <= vis[x][y][n])
            return 1;
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
            cout << vis[i][j][n];
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
            cout << vis[x][y][nc] - 1;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= H || y + dy[i] >= W)
                continue;
            if (board[x + dx[i]][y + dy[i]])
                continue;
            if (vis[x + dx[i]][y + dy[i]][nc])
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
            if (vis[x + ndx[i]][y + ndy[i]][nc])
                continue;
            vis[x + ndx[i]][y + ndy[i]][nc + 1] = vis[x][y][nc] + 1;
            q.push({x + ndx[i], y + ndy[i], nc + 1});
        }
    }
    cout << -1;
}
