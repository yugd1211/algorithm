#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> lst[101];

int bfs(int num)
{
    queue<int> q;
    int vis[101];
    fill(vis, vis + 101, -1);
    q.push(num);
    vis[num] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < lst[curr].size(); i++)
        {
            if (vis[lst[curr][i]] != -1)
                continue;
            q.push(lst[curr][i]);
            vis[lst[curr][i]] = vis[curr] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += vis[i];
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> vec;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        vec.push_back({bfs(i), i});
    sort(vec.begin(), vec.end());
    cout << vec[0].second;
}