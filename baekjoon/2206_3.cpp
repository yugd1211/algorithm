#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

// 풀이 자체가 오래걸림
// 기초적인 로직자체는 막힘없이 작성할 수 있었는데, 조건문에서 오래걸리고 반례찾기도 힘들었음
// 기본적인 풀이는 vis를 벽을 부수지 않은 배열과 벽을 부순 배열을 따로두고
// 벽을 부수지 않은 search에 한에서 벽을 부수고 진입하는 반복문을 실행하게 함
// 여기서 조건문이 복잡해지는게 벽을 부수지 않은 vis랑 벽을 부순 vis를 어떻게 구분하냐
// 벽을 부수고 나서도 일반적인 길에는 진입할 수 있으니 이것들을 통합해서 조건문을 작성하려고 하니 생각보다 어려웠음
// 벽을 부수는 반복문의 조건문은 까다롭지 않게 진행할 수 있는데
// 벽을 부수지 않은 vis와 벽을 부순 vis를 같은 반복문에서 처리하려고 하니 (반복문을 따로 둬도 그렇게 다르지 않았을거 같긴하다)
// 조건문이 중복되는 것들도 생기기 시작함 꽤 많은 테스트 케이스를 집어넣으면서 확인했는데, 그럴때마다 다 다른 케이스에서 터지고 무한반복하는 등.. 꽤 어려웠다.
// 그래도 혼자 힘으로 풀어서 뿌듯..

using namespace std;

int board[1001][1001];
int vis[1001][1001][2];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;

void printVis(int flag)
{
    cout << "===========================\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << vis[i][j][flag] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    queue<tuple<int, int, bool>> q;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char n;
            cin >> n;
            if (n == '1')
                board[i][j] = -1;
            else
                board[i][j] = 0;
        }
    }
    q.push({0, 0, 0});
    vis[0][0][0] = 1;
    while (!q.empty())
    {
        int x, y;
        bool isCrush;
        tie(x, y, isCrush) = q.front();
        q.pop();
        if (x == N - 1 && y == M - 1)
            break;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                continue;
            if (board[x + dx[i]][y + dy[i]] != 0)
                continue;
            if (vis[x + dx[i]][y + dy[i]][0])
                continue;
            if (vis[x + dx[i]][y + dy[i]][isCrush] <= vis[x][y][isCrush] + 1 && vis[x + dx[i]][y + dy[i]][isCrush] != 0)
                continue;
            vis[x + dx[i]][y + dy[i]][isCrush] = vis[x][y][isCrush] + 1;
            q.push({x + dx[i], y + dy[i], isCrush});
        }
        if (isCrush)
            continue;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= M)
                continue;
            if (vis[x + dx[i]][y + dy[i]][1])
                continue;
            if (vis[x + dx[i]][y + dy[i]][1] <= vis[x][y][1] + 1 && vis[x + dx[i]][y + dy[i]][1] != 0)
                continue;
            vis[x + dx[i]][y + dy[i]][1] = vis[x][y][isCrush] + 1;
            q.push({x + dx[i], y + dy[i], 1});
        }
    }
    int ans = min(vis[N - 1][M - 1][0], vis[N - 1][M - 1][1]);
    if (ans == 0)
        ans = max(vis[N - 1][M - 1][0], vis[N - 1][M - 1][1]);
    if (ans == 0)
        cout << "-1";
    else
        cout << ans;
}