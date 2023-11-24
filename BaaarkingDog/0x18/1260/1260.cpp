#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
int ver[1001][1001];
int dfsVis[1001];
int bfsVis[1001];
queue<int> q;

// 일단 인덱싱을 잘하자 i = 0이 아니라 1부터 시작해야된다.
// 재귀 dfs의 인자를 잘못줬다. 그래프를 처음하다보니 인자로 주는 인덱스를 착각했다.
void dfs(int curr)
{
    if (dfsVis[curr])
        return;
    dfsVis[curr] = 1;
    cout << curr << " ";
    for (int i = 1; i <= N; i++)
        if (ver[curr][i] && !dfsVis[i])
            dfs(i);
}

void bfs(int curr)
{
    q.push(curr);
    bfsVis[curr] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 1; i <= N; i++)
        {
            if (ver[curr][i] && !bfsVis[i])
            {
                bfsVis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> N;
    cin >> M;
    cin >> V;
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u;
        cin >> v;
        ver[u][v] = 1;
        ver[v][u] = 1;
    }
    dfs(V);
    cout << "\n";
    bfs(V);
}
