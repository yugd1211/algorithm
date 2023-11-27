#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// 처음 문제의 이해를 잘 못했다.
// 문제를 해석하면 루트는 1부터 시작한다.
// 입력으로 간선들이 주어지는데 이를 루트 1을 기준으로 부모와 자식이 결정된다.
// 1이랑 연결된 이들은 무조건 자식들 그 자식들과 연결된 ......
// 자식의 제한을 두지 않았다.

vector<int> adj[100001];
int parent[100001];

int N;

void dfs(int curr)
{
    for (int next : adj[curr])
    {
        // adj에는 부모 자식 구분없이 들어가 있기 때문에 부모는 건너뛴다.
        if (next == parent[curr])
            continue;
        // 자식의 부모를 자신으로 설정
        parent[next] = curr;
        dfs(next);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u;
        int v;
        cin >> u;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";
    return 0;
}