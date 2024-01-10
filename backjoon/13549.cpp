#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int vis[200002];

int N, K;
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>>
    pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    pq.push({0, N});
    vis[N] = 0;
    while (!pq.empty())
    {
        int curr, h;
        tie(h, curr) = pq.top();
        pq.pop();
        if (curr == K)
        {
            cout << h;
            break;
        }
        if (curr && curr / 2 <= 50000 && !vis[curr * 2])
        {
            pq.push({h, curr * 2});
            vis[curr * 2] = vis[curr];
        }
        if (curr + 1 <= K && !vis[curr + 1])
        {
            pq.push({h + 1, curr + 1});
            vis[curr + 1] = vis[curr] + 1;
        }
        if (curr - 1 >= 0 && !vis[curr - 1])
        {
            pq.push({h + 1, curr - 1});
            vis[curr - 1] = vis[curr] + 1;
        }
    }
}