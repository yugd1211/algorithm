#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<int> (&adj)[501], int (&p)[501], int curr)
{
    queue<int> q;
    q.push(curr);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < adj[curr].size(); i++)
        {
            int c = adj[curr][i];
            if (c == p[curr])
                continue;
            if (p[c])
                return 0;
            q.push(adj[curr][i]);
            p[c] = curr;
        }
    }
    return 1;
}

int main()
{
    int t = 1;
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (1)
    {
        vector<int> adj[501];
        int p[501];
        int T = 0;
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        fill(p, p + 501, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
            T += bfs(adj, p, i);
        }
        if (T > 1)
            cout << "Case " << t++ << ": A forest of " << T << " trees.\n";
        else if (T == 1)
            cout << "Case " << t++ << ": There is one tree.\n";
        else
            cout << "Case " << t++ << ": No trees.\n";
    }
}