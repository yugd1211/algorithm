#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int adj[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int dest) {
    vector<int> answer;
    vector<int> edge[100001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    adj[dest] = 1;
    pq.push({0, dest});
    while (!pq.empty())
    {
        int cost, dest;
        tie(cost, dest) = pq.top();
        pq.pop();
        for (int i = 0; i < edge[dest].size(); i++)
        {
            int next = edge[dest][i];
            if (adj[next])
                continue;
            adj[next] = adj[dest] + 1;
            pq.push({adj[next], next});
        }
    }
    for (int i = 0; i < sources.size(); i++)
        answer.push_back(adj[sources[i]] - 1);
    return answer;
}