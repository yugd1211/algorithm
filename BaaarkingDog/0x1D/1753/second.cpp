#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define DEST first
#define COST second
#define INF 1000000000
int V, E, st;
vector<pair<int, int>> adj[20001];
int arr[20001];

// 메모리 초과 발생
// pair로 바꿔도 똑같이 메모리 초과 발생
// 67%

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> st;
    for (int i = 0; i <= V; i++)
        arr[i] = INF;
    arr[st] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    for (int i = 0; i < adj[st].size(); i++)
    {
        int u = st;
        int v = adj[st][i].DEST;
        int cost = adj[st][i].COST;
        pq.push({cost, v});
    }
    while (!pq.empty())
    {
        int cost, v;
        tie(cost, v) = pq.top();
        pq.pop();
        if (arr[v] < cost)
            continue;
        arr[v] = cost;
        for (int i = 0; i < adj[v].size(); i++)
        {
            int nextV = adj[v][i].DEST;
            int nextCost = adj[v][i].COST;
            if (cost + nextCost < arr[nextV])
                pq.push({cost + nextCost, nextV});
        }
    }
    for (int i = 1; i <= V; i++)
    {
        if (arr[i] == INF)
            cout << "INF\n";
        else
            cout << arr[i] << "\n";
    }
    return 0;
}