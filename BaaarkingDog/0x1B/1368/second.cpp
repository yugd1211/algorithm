#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

// 풀이법
// 처음 우물을 파는 것을 새로운 노드로 만들고 우물을 파는 비용을 해당노드와의 간선으로 새로 만든다.

int p[303];

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
// cost, u, v
tuple<int, int, int> adj[100005];

int e;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v;
    for (int i = 1; i <= v; i++)
    {
        int cost;
        cin >> cost;
        p[i] = i;
        adj[e++] = {cost, i, v + 1};
    }

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
    v++;
    sort(adj, adj + e);
    int cnt = 0;
    long long total = 0;
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