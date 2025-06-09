#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
vector<int> adj[51];
bool vis[51][51];

void dfs(int depth, int p, int curr)
{
    if (depth > 2) 
        return;
    if (p == curr) 
        return;

    if (!vis[p][curr])
        vis[p][curr] = true;

    for (auto iter : adj[curr])
    {
        dfs(depth + 1, p, iter);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            if (c == 'Y')
                adj[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (auto iter : adj[i])
            dfs(1, i, iter);
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (i != j && vis[i][j])
                cnt++;
        }
        answer = max(answer, cnt);
    }

    cout << answer;
}