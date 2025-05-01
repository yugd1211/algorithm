#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// s to 1 to a + b
// s to s to a + b
vector<pair<int, int>> edges[201];

int adj[3][201];

void PrintAdj(int adj[201], int n)
{
    cout << "========adj===========\n";
    for (int i = 1; i <= n; i++)
        cout << adj[i] << ", ";
    cout << "\n";
}

void FaresToEdges(vector<vector<int>> &fares)
{
    for (int i = 0; i < fares.size(); i++)
    {
        int st = fares[i][0];
        int en = fares[i][1];
        int de = fares[i][2];
        edges[st].push_back({de, en});
        edges[en].push_back({de, st});
    }
}

void Dijkstra(int s, int *arr)
{
    // degree, st, en
    priority_queue<tuple<int, int, int>, 
                    vector<tuple<int, int, int>>, 
                    greater<tuple<int, int, int>>> pq;
        
    for (int i = 0; i < edges[s].size(); i++)
        pq.push({edges[s][i].first, s, edges[s][i].second});
    while (!pq.empty())
    {
        int st, en, de;
        tie(de, st, en) = pq.top();
        pq.pop();
        
        if (arr[en] != 0 && arr[en] < de)
            continue;
        arr[en] = de;
        for (int i = 0; i < edges[en].size(); i++)
            pq.push({edges[en][i].first + de, en, edges[en][i].second});
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 2100000000;
    
    FaresToEdges(fares);
    
    for (int i = 0; i < 3; i++)
    {
        fill(adj[i], adj[i] + 201, 2100000000);
    }
    Dijkstra(s, adj[0]);
    Dijkstra(a, adj[1]);
    Dijkstra(b, adj[2]);
    adj[0][s] = 0;
    adj[1][a] = 0;
    adj[2][b] = 0;
 
    for (int i = 1; i <= n; i++)
        answer = min(answer, adj[0][i] + adj[1][i] + adj[2][i]);
    return answer;
}