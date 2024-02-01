#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans;
int root;
vector<int> adj[51];
int p[51];

void bfs(int n)
{
    if (adj[n].empty())
        ans++;
    for (int i = 0; i < adj[n].size(); i++)
    {
        int nxt = adj[n][i];
        bfs(nxt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            root = i;
            continue;
        }
        p[i] = n;
        adj[n].push_back(i);
    }
    int e;
    cin >> e;
    if (e == root)
    {
        cout << 0;
        return 0;
    }
    adj[p[e]].erase(find(adj[p[e]].begin(), adj[p[e]].end(), e));
    bfs(root);
    cout << ans;
}