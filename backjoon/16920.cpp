#include <iostream>
#include <algorithm>
#include <queue>
#define WALL -1

using namespace std;
void printBoard();

// 처음에 문제 이해를 잘못해서 구조를 잘못잡았는데
// 이 구조로 이어나갈려고하다보니 괴상해졌다.

// 문제풀이
// bfs를 두번 실행하는 형식이다.
// 처음 bfs는 라운드에 대한 bfs이다.
// 두번째 bfs는 해당 라운드에서 움직일수 있는 횟수를가지고 bfs를 실행해서 해당 라운드에
// 갈 수 있는 최대 거리까지 성을 먹는형식이다.
// 여기서 간과한건 vis에 이미 간적이 있으면 search가 종료된다.
// 하지만 횟수의 차이로 마지막 횟수로 도착한 위치에 방문표시를 하면
// 아직 더 나아갈수있는 search가 해당 방문표시를 보고 그만둬버린다.
// 그래서 vis에 횟수를 저장하는 방식으로 하려고했는데 이동횟수의 크기가 10^9이기 때문에
// 메모리초과로 이방법도 사용하지 못한다.
// 그래서 다른 방식의 풀이를 생각해봐야한다.
// 생각한 방식은 vis를 pair로 만들어서 해당위치의 횟수를 저장하는방식이다.
// 해당 위치에 도달해도 해당 위치의 이동횟수보다 많은 이동횟수가 남으면 계속 search를 진행하고
// 해당 이동횟수보다 낮으면 search를 그만두는 방식이다.

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, P;
int board[1001][1001];
int vis[1001][1001];
int pm[10];
queue<pair<int, int>> q;

bool cA()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!board[i][j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++)
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
    for (int p = 1; p <= P; p++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == p)
                    q.push({i, j});
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        queue<tuple<int, int, int>> q2;
        q2.push({x, y, pm[board[x][y]]});
        while (!q2.empty())
        {
            int x2, y2, cnt;
            tie(x2, y2, cnt) = q2.front();
            q2.pop();
            if (cA())
                break;
            if (!cnt)
                continue;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = dx[dir] + x2;
                int ny = dy[dir] + y2;
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (board[nx][ny] != 0 && board[nx][ny] != board[x][y])
                    continue;
                if (!board[nx][ny])
                    q.push({nx, ny});
                board[nx][ny] = board[x][y];
                q2.push({nx, ny, cnt - 1});
            }
        }
        if (cA())
            break;
    }
    fill(pm, pm + 10, 0);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            pm[board[i][j]]++;
    for (int i = 1; i <= P; i++)
        cout << pm[i] << " ";
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