#include <iostream>
#include <algorithm>
#include <vector>

// 문제풀이
// 서브트리에 속한 정점의 수는 해당 노드읠 자식 노드들의 정점의 수 + 1(자기자신을 포함한 서브트리)이다.
// 자식 서브트리의 정점의수를 구하기 위해서 dfs를 실행해서 구할수 있다.
// 근대 여기서 트리 자체는 수정되지 않으므로 노드들의 정점의 수 자체는 변하지 않는다.
// 그렇기 때문에 미리 구한 값을 저장해두면 쿼리마다 dfs를 구할 필요가 없다.

using namespace std;

int N, R, Q;

vector<int> adj[100001];
int p[100001];
int dp[100001];

void dfs(int parent)
{
    if (adj[parent].empty())
        return;
    for (int i = 0; i < adj[parent].size(); i++)
    {
        int c = adj[parent][i];
        if (c == p[parent])
            continue;
        p[c] = parent;
        dfs(c);
        dp[parent] += dp[c];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> R >> Q;
    fill(dp, dp + 100001, 1);
    for (int i = 1; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    p[R] = R;
    dfs(R);
    for (int i = 0; i < Q; i++)
    {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}
