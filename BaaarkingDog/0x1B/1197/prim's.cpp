#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#define COST first
#define DEST second
using namespace std;

// cost, dest
vector<pair<int, int>> adj[10002];
int p[10002];
priority_queue<tuple<int, int, int>,
               vector<tuple<int, int, int>>,
               greater<tuple<int, int, int>>>
    pq;

int V, E;
int total;

int main()
{
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }
    p[1] = 1;
    for (auto next : adj[1])
        pq.push({next.COST, 1, next.DEST});
    int cnt = 0;
    while (cnt < V - 1)
    {
        auto top = pq.top();
        pq.pop();
        if (p[get<2>(top)])
            continue;
        p[get<2>(top)] = 1;
        total += get<0>(top);
        for (auto next : adj[get<2>(top)])
            if (!p[next.DEST])
                pq.push({next.COST, get<2>(top), next.DEST});
        cnt++;
    }
    cout << total;
}
