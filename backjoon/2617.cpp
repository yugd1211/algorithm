#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제 풀이
// 우리가 찾아야 되는 것은 중간일 수 없는 번호이다.
// 중간인 구슬은 나보다 가벼운 구슬이 (N + 1) / 2개이고, 나보다 무거운 구슬이 (N + 1) / 2개이다.
// 그말은 나보다 무거운 구슬이 (N + 1) / 2 이상이거나
// 나보다 가벼운 구슬이 (N + 1) / 2 이상인 구슬은 제외할 수 있다.
// 어떻게 나보다 무거운 구슬들을 모두 체크할 수 있는가하면 그래프를 그렸을때 확인할 수 있었다.
// 그래프를 무거운 구슬이 가벼운 구슬을 가리키게 만들었을때, 그러면 나를 가리키는 간선들은 모두 나보다 무겁다고 단정 지을수있다.
// 그러면 나를 가리키는 구슬들보다 무거운 구슬들도 나보다 무겁다라는 걸 알 수 있다.
// 그래서 bfs로 나보다 무거운 간선들을 모두 찾아내서 count해주면된다.
// 반대로 나보다 가벼운 간선들또한 똑같이 찾을 수 있으니 나보다 무거운 구슬이 (N + 1) / 2 이상이거나 가여운 구슬이 (N + 1) / 2 이상이면 ans를 올려준다.

int N, M;

vector<int> heavy[100];
vector<int> light[100];

bool isHeavy(int num)
{
    queue<int> q;
    bool vis[100];
    int cnt = 0;

    fill(vis, vis + 100, 0);
    if (heavy[num].empty())
        return 0;
    q.push(num);
    vis[num] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < heavy[curr].size(); i++)
        {
            int nxt = heavy[curr][i];
            if (vis[nxt])
                continue;
            q.push(nxt);
            cnt++;
            vis[nxt] = 1;
        }
    }
    if (cnt >= (N + 1) / 2)
        return 1;
    else
        return 0;
}

bool isLight(int num)
{
    queue<int> q;
    bool vis[100];
    int cnt = 0;

    fill(vis, vis + 100, 0);
    if (light[num].empty())
        return 0;
    q.push(num);
    vis[num] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < light[curr].size(); i++)
        {
            int nxt = light[curr][i];
            if (vis[nxt])
                continue;
            q.push(nxt);
            cnt++;
            vis[nxt] = 1;
        }
    }
    if (cnt >= (N + 1) / 2)
        return 1;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        heavy[a].push_back(b);
        light[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (isHeavy(i) || isLight(i))
            ans++;
    }
    cout << ans;
}
