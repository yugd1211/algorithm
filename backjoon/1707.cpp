#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;

bool checkBipartite(int N, vector<int> (&lst)[20001], int (&vis)[20001])
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < lst[i].size(); j++)
        {
            int nxt = lst[i][j];
            if (vis[i] && vis[i] == vis[nxt])
                return 0;
        }
    }
    return 1;
}

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<int> lst[20001];
        queue<int> q;
        int vis[20001];
        fill(vis, vis + 20001, 0);
        int N, M;
        cin >> N >> M;
        for (int j = 0; j < M; j++)
        {
            int a, b;
            cin >> a >> b;
            lst[a].push_back(b);
            lst[b].push_back(a);
        }
        for (int st = 1; st <= N; st++)
        {
            if (vis[st])
                continue;
            q.push(st);
            vis[st] = 1;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int i = 0; i < lst[curr].size(); i++)
                {
                    int nxt = lst[curr][i];
                    if (vis[nxt])
                        continue;
                    vis[nxt] = (vis[curr] == 1) ? 2 : 1;
                    q.push(nxt);
                }
            }
        }
        if (checkBipartite(N, lst, vis))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}