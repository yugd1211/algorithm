#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> lst[20001];
vector<int> vec;
int vis[20001];
queue<int> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < lst[curr].size(); i++)
        {
            int nxt = lst[curr][i];
            if (vis[nxt])
                continue;
            vis[nxt] = vis[curr] + 1;
            q.push(nxt);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
        cnt = max(cnt, vis[i]);
    for (int i = 1; i <= N; i++)
        if (cnt == vis[i])
            vec.push_back(i);
    cout << vec[0] << " " << vis[vec[0]] - 1 << " " << vec.size();
}
