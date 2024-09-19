#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int adj[101][101];
int vis[101];
int N;

void clearAdj()
{
    for (int i = 0; i <= 100; i++)
        fill(adj[i], adj[i] + 101, 0);
}

void clearVis()
{
    fill(vis, vis + 101, 0);
}

void dfs(int curr, int cnt)
{
    vis[curr] = cnt;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i])
            continue;
        if (!adj[curr][i] &&!adj[i][curr])
            continue;
        dfs(i, cnt);
    }
}

int solution(int n, vector<vector<int>> wires) 
{
    int answer = 100000000;
    N = n;
    for (int j = 0; j < wires.size(); j++)
    {
        clearAdj();
        clearVis();
        for (int i = 0; i < wires.size(); i++)
        {
            if (i == j)
                continue;
            adj[wires[i][0]][wires[i][1]] = 1;
            adj[wires[i][1]][wires[i][0]] = 1;
        }
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;
            dfs(i, cnt++);
        }
        int a = 0;
        int b = 0;
        for (int i = 1; i<= n; i++)
        {
            if (vis[i] == 1)
                a++;
            else if (vis[i] == 2)
                b++;
        }
        int res = abs(a - b);
        answer = min(res, answer);
    }
    return answer;
}