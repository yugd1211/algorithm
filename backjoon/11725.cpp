#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100001];
int p[100001];

int N;

void dfs(int parent)
{
    for (int i = 0; i < adj[parent].size(); i++)
    {
        int c = adj[parent][i];
        if (p[c])
            continue;
        p[c] = parent;
        dfs(c);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for (int i = 2; i <= N; i++)
    {
        cout << p[i] << "\n";
    }
}