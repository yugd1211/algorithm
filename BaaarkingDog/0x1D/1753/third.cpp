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

// 다른 사람의 코드를 보고 조건문을 바꾸긴 했는데 왜 어떤 문제 때문에 이렇게 차이가 나는지는 정확하게 이해하지는 못함..

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> st;
    for (int i = 0; i <= V; i++)
        arr[i] = INF;
    for (int i = 0; i < E; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    arr[st] = 0;
    pq.push({0, st});
    while (!pq.empty())
    {
        int cost, v;
        tie(cost, v) = pq.top();
        pq.pop();
        if (arr[v] != cost)
            continue;
        for (int i = 0; i < adj[v].size(); i++)
        {
            int nextV = adj[v][i].DEST;
            int nextCost = adj[v][i].COST;
            if (arr[nextV] <= cost + nextCost)
                continue;
            arr[nextV] = cost + nextCost;
            pq.push({arr[nextV], nextV});
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