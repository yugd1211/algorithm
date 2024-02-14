#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;

vector<int> com[101];
int vis[101];

int main()
{
    queue<int> q;
    int ans = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    vis[1] = 1;
    q.push(1);
    for (int i = 0; i < com[1].size(); i++)
    {
        q.push(com[1][i]);
        vis[com[1][i]] = 1;
    }
    while (!q.empty())
    {
        ans++;
        int curr = q.front();
        q.pop();
        for (int i = 0; i < com[curr].size(); i++)
        {
            if (vis[com[curr][i]])
                continue;
            q.push(com[curr][i]);
            vis[com[curr][i]] = 1;
        }
    }
    cout << ans - 1;
}