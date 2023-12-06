#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
using namespace std;
#define INF 1000000000

int n, m;

// cost, dest
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
// dest, cost
vector<pair<int, int>> bus[1001];
int d[1001];
int pre[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        bus[u].push_back({v, cost});
    }
    int st, en;
    cin >> st >> en;
    d[st] = 0;
    pre[st] = 0;
    pq.push({0, st});
    while (!pq.empty())
    {
        int curr_cost = pq.top().first;
        int curr_dest = pq.top().second;
        pq.pop();
        if (d[curr_dest] != curr_cost)
            continue;
        for (int i = 0; i < bus[curr_dest].size(); i++)
        {
            int next_dest = bus[curr_dest][i].first;
            int next_cost = bus[curr_dest][i].second;
            if (d[next_dest] <= d[curr_dest] + next_cost)
                continue;
            d[next_dest] = d[curr_dest] + next_cost;
            pq.push({d[next_dest], next_dest});
            pre[next_dest] = curr_dest;
        }
    }
    int curr = en;
    stack<int> stk;
    cout << d[en] << "\n";
    while (curr)
    {
        stk.push(curr);
        curr = pre[curr];
    }
    cout << stk.size() << "\n";
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}