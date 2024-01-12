#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제풀이
// 그래프와 bfs를 혼합해서 풀었다.
// 먼저 불을 킬수 있는 스위치를 그래프로 만들어서 묶었다.
// bfs는 존이 움직일 수있는 위치를 search한다.
// 존이 불이 켜진 방에 도착하면 vis를 업데이트하고 해당 방의 그래프들을 꺼내서 불을 킨다.
// 이제 존이 움직일 수 있는 곳(불이 켜진곳)을 queue에 추가해줘한다.
// 하지만 존은 인접한 방밖에 움직일 수 없고 불은 그랑 상관없이 전체 방의 불을 킬수 있다.
// 그래서 존이 방문한 모든 곳을 순회하며 해당 방에서 인접한곳에 불이 켜져있는지를 확인하고 해당 방으로 이동한다.
// 이 때 중요한 점은 queue에 추가할 방이 이미 방문한 곳인지를 확인해줘야 한다(확인하지 않으면 무한루프).

bool vis[101][101];
bool light[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
vector<pair<int, int>> g[101][101];

void printVis()
{
    cout << "===================vis===================\n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << vis[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        g[x][y].push_back({a, b});
    }
    vis[1][1] = 1;
    light[1][1] = 1;
    q.push({1, 1});
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < g[x][y].size(); i++)
        {
            int nx, ny;
            tie(nx, ny) = g[x][y][i];
            if (vis[nx][ny])
                continue;
            light[nx][ny] = 1;
        }
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (!vis[i][j])
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if (nx < 0 || ny < 0 || nx > N || ny > N)
                        continue;
                    if (!light[nx][ny] || vis[nx][ny])
                        continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (light[i][j])
                ans++;
    printVis();
    cout << ans;
}
