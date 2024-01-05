#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int board[301][301];
int vis[301][301];
queue<pair<int, int>> q;

int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void clearVis()
{
    for (int i = 0; i < 301; i++)
        for (int j = 0; j < 301; j++)
            vis[i][j] = 0;
}

void isDivide()
{
    int cnt = 0;
    queue<pair<int, int>> q2;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!board[i][j])
                continue;
            clearVis();
            q2.push({i, j});
            cnt++;
            while (q2.empty())
            {
                int x, y;
                tie(x, y) = q2.front();
                for (int i = 0; i < 4; i++)
                {
                    if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                        continue;
                    if (board[x + dx[i]][y + dy[i]] == 0)
                        continue;
                    if (vis[x + dx[i]][y + dy[i]])
                        continue;
                    q2.push({x + dx[i], y + dy[i]});
                    vis[x + dx[i]][y + dy[i]] = cnt;
                }
            }
        }
    }
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
    while (q.empty())
    {
        vector<tuple<int, int, int>> vec;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x, y;
            tie(x, y) = q.front();
            int h = board[x][y];
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                    continue;
                if (board[x + dx[i]][y + dy[i]] == 0)
                    --h;
            }
            vec.push_back({x, y, h});
        }
        for (int i = 0; i < vec.size(); i++)
        {
            int x, y, h;
            tie(x, y, h) = vec[i];
            board[x][y] = h;
            if (board[x][y])
                q.push({x, y});
        }

        ans++;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
            {
                cout << ans;
            }
        }
    }
    cout << ans;
}