#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

// 풀이법
// 논들의 거리값으로 최소 스패닝 트리 알고리즘을 적용해서 최소값을 구한다.
// 하지만 이렇게 하면 우물을 팔수 없으니까 그중 제일 우물파는 비용이 작은 곳의 우물을 판다.
// 처음에는 뭐가 잘못됐는지 모르고 머리를 싸매고 하루종일 생각을 해봤다.
// 근대 당연히 틀렸다..
// 우물을 굳이 하나만 팔 필요가없다.
// 극단적으로 모든 논에서의 우물파는비용이 1이고 모든 논에서 논으로 물을 길러오는 작업이 2이상일때
// 모든 논에서 우물을 파는게 최소이기 때문이다.

using namespace std;

int p[301];

int find(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}

int union_find(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return 0;
    p[a] = b;
    return 1;
}

int v;

int W[301];
long long total;
// cost, u, v
tuple<int, int, int> adj[100004];

int e;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v;
    int wMin = 0;
    W[0] = 1000000;
    for (int i = 1; i <= v; i++)
    {
        cin >> W[i];
        p[i] = i;
        if (W[wMin] > W[i])
            wMin = i;
    }
    total = W[wMin];
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            int cost;
            cin >> cost;
            if (j <= i)
                continue;
            adj[e++] = {cost, i, j};
        }
    }
    sort(adj, adj + e);
    int cnt = 0;
    for (int i = 0; i < e; i++)
    {
        int cost, a, b;
        tie(cost, a, b) = adj[i];
        if (!union_find(a, b))
            continue;
        total += cost;
        cnt++;
        if (cnt == v - 1)
            break;
    }
    cout << total;
}