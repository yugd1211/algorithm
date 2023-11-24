#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> vec[1001];
bool vis[1001];
int ret;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    queue<int> q;
    for (int i = 0; i < M; i++)
    {
        int u;
        int v;
        cin >> u;
        cin >> v;
        vec[v].push_back(u);
        vec[u].push_back(v);
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (vec[i].empty() || vis[i])
            continue;
        ret++;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int j = 0; j < vec[curr].size(); j++)
            {
                if (!vis[vec[curr][j]])
                {
                    q.push(vec[curr][j]);
                    vis[vec[curr][j]] = 1;
                }
            }
        }
    }
    // 정점은 있지만 간선은 없을 경우
    // 정점의 numbering도 없는데..
    int verCnt = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (vis[i])
            verCnt++;
    }
    ret += N - verCnt;
    cout << ret;
    return 0;
}