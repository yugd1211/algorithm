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
// 이유를 생각해봤을때 첫번째는 tuple의 인자가 3개라?
// 현재 queue에 cost, u, v로 선언해서 간선 자체를 담고 있는데
// u를 빼면 1/3이 일단 줄기 때문에 이부분을 줄이고자 한다.
// 간선 자체를 담는게 아니라 해당 간선의 cost와 이전 위치의 cost를 더한 값과 v를 담는다.

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

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
        pq.push({cost, u, v});
    }
    while (!pq.empty())
    {
        int cost, u, v;
        tie(cost, u, v) = pq.top();
        pq.pop();
        if (arr[v] < arr[u] + cost)
            continue;
        arr[v] = arr[u] + cost;
        for (int i = 0; i < adj[v].size(); i++)
        {
            int nextU = v;
            int nextV = adj[v][i].DEST;
            int nextCost = adj[v][i].COST;
            // 푸쉬 자체를 막으니까 2% -> 67%까지는 통과했지만 어찌됐든 메모리 초과 발생
            if (arr[nextV] > arr[nextU] + nextCost)
                pq.push({nextCost, nextU, nextV});
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