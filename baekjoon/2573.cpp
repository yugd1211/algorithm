#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int board[301][301];
queue<pair<int, int>> q;

int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void clearArr(int arr[301][301])
{
    for (int i = 0; i < 301; i++)
        for (int j = 0; j < 301; j++)
            arr[i][j] = 0;
}

void Swap(int tmp[301][301])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            board[i][j] = tmp[i][j];
}

void printBoard(int arr[301][301])
{
    cout << "==================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

int bfs()
{
    int cnt = 0;
    int tmp[301][301];
    clearArr(tmp);
    queue<pair<int, int>> q2;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] && !tmp[i][j])
            {
                cnt++;
                q2.push({i, j});
                tmp[i][j] = cnt;
                while (!q2.empty())
                {
                    int x, y;
                    tie(x, y) = q2.front();
                    q2.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        if (x + dx[k] < 0 || y + dy[k] < 0 || x < dx[k] >= N || y < dy[k] >= M)
                            continue;
                        if (tmp[x + dx[k]][y + dy[k]])
                            continue;
                        if (board[x + dx[k]][y + dy[k]])
                        {
                            tmp[x + dx[k]][y + dy[k]] = cnt;
                            q2.push({x + dx[k], y + dy[k]});
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                q.push({i, j});
        }
    }

    while (!q.empty())
    {
        int size = q.size();
        int tmp[301][301];

        clearArr(tmp);
        for (int i = 0; i < size; i++)
        {
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            tmp[x][y] = board[x][y];
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= N || y + dy[i] >= M)
                    continue;
                if (tmp[x][y] <= 0)
                    break;
                if (!board[x + dx[i]][y + dy[i]])
                    tmp[x][y]--;
            }
            if (tmp[x][y] < 0)
                tmp[x][y] = 0;
            if (tmp[x][y])
                q.push({x, y});
        }
        ans++;
        Swap(tmp);
        if (bfs() >= 2)
        {
            cout << ans;
            return 0;
        }
    }
    cout << 0;
}