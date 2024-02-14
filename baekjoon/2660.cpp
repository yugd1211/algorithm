#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> lst[51];
int score[51];

void bfs(int num)
{
    int vis[51];
    fill(vis, vis + 51, 0);
    queue<int> q;
    int ans = 0;
    vis[num] = 1;
    for (int i = 0; i < lst[num].size(); i++)
    {
        q.push(lst[num][i]);
        vis[lst[num][i]] = 1;
    }
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
    for (int i = 1; i <= N; i++)
        score[num] = max(score[num], vis[i]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    vector<int> ans;
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;
        lst[a].push_back(b);
        lst[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        bfs(i);
    int _min = score[1];
    for (int i = 2; i <= N; i++)
        _min = min(_min, score[i]);
    for (int i = 1; i <= N; i++)
    {
        if (score[i] == _min)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());

    cout << _min << " " << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}