#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
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
    p[b] = a;
    return 1;
}

int N;

int W[301];
long long total;
// cost, u, v
tuple<int, int, int> adj[100004];

int main()
{
    cin >> N;
    int wMin = 0;
    W[0] = 1000000;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
        p[i] = i;
        if (W[wMin] > W[i])
            wMin = i;
    }
    total = W[wMin];
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cost;
            cin >> cost;
            adj[i * j] = {cost, i, j};
        }
    }
    sort(adj, adj + N);
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int cost, a, b;
            tie(cost, a, b) = adj[i * j];
            if (!union_find(a, b))
                continue;
            total += cost;
            cnt++;
            if (cnt == N - 1)
                break;
        }
    }
    cout << total;
}