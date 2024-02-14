#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100001];
bool vis[100001];
vector<int> p[100001];

int N, M, ans;

bool isParent(int n, int c)
{
    for (int i = 0; i < p[n].size(); i++)
    {
        int parent = p[n][i];
        if (parent == c)
            return 1;
    }
    return 0;
}

void pickParent(int n)
{
    for (int i = 0; i < adj[n].size(); i++)
    {
        int nxt = adj[n][i];
        if (isParent(n, nxt))
            continue;
        p[nxt].push_back(n);
    }
}

void visit(int n)
{
    for (int i = 0; i < adj[n].size(); i++)
    {
        int nxt = adj[n][i];
        if (vis[nxt])
            continue;
        vis[nxt] = 1;
        visit(nxt);
    }
}

void pairing()
{
    visit(1);
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            visit(i);
            adj[1].push_back(i);
            ans++;
        }
    }
}

void parentCounting()
{
    for (int i = 2; i <= N; i++)
    {
        if (p[i].size() < 2)
            continue;
        ans += p[i].size() - 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        pickParent(i);
    pairing();
    parentCounting();
    cout << ans;
}
