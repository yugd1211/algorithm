#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int p[100001];
vector<int> adj[100001];
int praise[100001];

int N, M;

void praiseDown(int sub, int w)
{
    praise[sub] += w;
    for (int i = 0; i < adj[sub].size(); i++)
    {
        int c = adj[sub][i];
        praiseDown(c, praise[sub]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int boss;
    for (int c = 1; c <= N; c++)
    {
        cin >> p[c];
        if (p[c] == -1)
        {
            boss = c;
            continue;
        }
        adj[p[c]].push_back(c);
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        praise[a] += b;
    }
    praiseDown(boss, praise[boss]);
    for (int i = 1; i <= N; i++)
        cout << praise[i] << " ";
}