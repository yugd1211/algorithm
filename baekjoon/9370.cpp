#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 1000000000;

int T;
int n, m, t;
int s, g, h;

vector<pair<int, int>> edges[2001];

vector<int> dijkstra(int start)
{
    vector<int> dist(n + 1, MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (dist[curr] < cost)
            continue;

        for (int i = 0; i < edges[curr].size(); i++)
        {
            int next = edges[curr][i].second;
            int nextCost = cost + edges[curr][i].first;

            if (dist[next] > nextCost)
            {
                dist[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }

    return dist;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        vector<int> candidate;

        // 초기화
        for (int i = 0; i < 2001; i++)
        {
            edges[i].clear();
        }

        // 입력
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        for (int i = 0; i < m; i++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            edges[u].push_back({cost, v});
            edges[v].push_back({cost, u});
        }
        for (int i = 0; i < t; i++)
        {
            int can;
            cin >> can;
            candidate.push_back(can);
        }

        // s, g, h 노드에서의 다익스트라 실행
        vector<int> distFromS = dijkstra(s);
        vector<int> distFromG = dijkstra(g);
        vector<int> distFromH = dijkstra(h);

        vector<int> result;
        for (int dest : candidate)
        {
            // s->dest 최단거리와 s->g->h->dest 또는 s->h->g->dest 거리 비교
            if (distFromS[dest] == distFromS[g] + distFromG[h] + distFromH[dest] ||
                distFromS[dest] == distFromS[h] + distFromH[g] + distFromG[dest])
                result.push_back(dest);
        }

        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << "\n";
    }
}