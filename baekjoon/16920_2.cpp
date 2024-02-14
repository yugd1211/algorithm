#include <iostream>
#include <algorithm>
#include <queue>
#define WALL -1
#define P first
#define SP second

using namespace std;
void printBoard();
void printVis();

// 그래서 다른 방식의 풀이를 생각해봐야한다.
// 생각한 방식은 vis를 pair로 만들어서 해당위치의 횟수를 저장하는방식이다.
// 해당 위치에 도달해도 해당 위치의 이동횟수보다 많은 이동횟수가 남으면 계속 search를 진행하고
// 해당 이동횟수보다 낮으면 search를 그만두는 방식이다.
// search를 그만 두는 조건문을 만드느게 어려웠다. 여러개의 조건문을 추가하다보니 휴먼에러도 많았다....

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, g_P;
int board[1001][1001];
pair<int, int> vis[1001][1001];
int pm[10];
// x, y, sp
queue<tuple<int, int, int>> q;

int main()
{
    cin >> N >> M >> g_P;
    for (int i = 1; i <= g_P; i++)
        cin >> pm[i];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                board[i][j] = 0;
            else if (c == '#')
                board[i][j] = WALL;
            else
                board[i][j] = c - '0';
        }
    }
    for (int p = 1; p <= g_P; p++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] == p)
                {
                    q.push({i, j, pm[board[i][j]]});
                    vis[i][j] = {p, pm[board[i][j]]};
                }
            }
        }
    }
    while (!q.empty())
    {
        int x, y, sp;
        tie(x, y, sp) = q.front();
        q.pop();
        queue<tuple<int, int, int>> q2;
        q2.push({x, y, sp});
        while (!q2.empty())
        {
            int x, y, sp;
            tie(x, y, sp) = q2.front();
            q2.pop();
            if (!sp)
            {
                if (!vis[x][y].SP)
                    q.push({x, y, pm[vis[x][y].P]});
                continue;
            }
            int p = vis[x][y].P;
            for (int i = 0; i < 4; i++)
            {
                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (board[nx][ny])
                    continue;
                if (vis[nx][ny].P && (vis[nx][ny].P != p || vis[nx][ny].SP >= sp - 1))
                    continue;
                vis[nx][ny] = {p, sp - 1};
                q2.push({nx, ny, sp - 1});
            }
        }
    }
    fill(pm, pm + 10, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            pm[vis[i][j].P]++;
    for (int i = 1; i <= g_P; i++)
        cout << pm[i] << " ";
    cout << " \n";
}

void printBoard()
{
    cout << "==============board===============\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == WALL)
                cout << "#";
            if (board[i][j] == 0)
                cout << '.';
            else
                cout << board[i][j];
        }
        cout << '\n';
    }
}
void printVis()
{
    cout << "==============vis===============\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vis[i][j].P == WALL)
                cout << "#";
            if (vis[i][j].P == 0)
                cout << '.';
            else
                cout << vis[i][j].P;
        }
        cout << '\n';
    }
}