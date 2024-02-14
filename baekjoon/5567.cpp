#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int ans;
int vis[501];
vector<int> lst[501];
queue<int> q;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    vis[1] = 1;
    for (int i = 0; i < lst[1].size(); i++)
    {
        q.push(lst[1][i]);
        vis[lst[1][i]] = 1;
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (vis[curr] >= 2)
            continue;
        for (int i = 0; i < lst[curr].size(); i++)
        {
            if (vis[lst[curr][i]])
                continue;
            vis[lst[curr][i]] = vis[curr] + 1;
            q.push(lst[curr][i]);
        }
    }
    for (int i = 1; i <= N; i++)
        if (vis[i])
            ans++;
    cout << ans - 1;
}