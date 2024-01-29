#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> lst[10001];
int cnt[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        lst[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        queue<int> q;
        bool vis[10001];
        fill(vis, vis + 10001, 0);
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < lst[curr].size(); j++)
            {
                int nxt = lst[curr][j];
                if (vis[nxt])
                    continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
        int n = 0;
        for (int j = 1; j <= N; j++)
            if (vis[j])
                n++;
        cnt[i] = n;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++)
        if (cnt[i])
            ans = max(ans, cnt[i]);
    for (int i = 1; i <= N; i++)
        if (cnt[i] == ans)
            cout << i << " ";
}