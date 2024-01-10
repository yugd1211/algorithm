#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int N, K;
int vis[200005];
int g_prev[200005];
queue<int> q;

int main()
{
    cin >> N >> K;
    q.push(N);
    for (int i = 0; i < 100001; i++)
        vis[i] = 1000000;
    for (int i = 0; i < 100001; i++)
        g_prev[i] = -1;
    vis[N] = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == K)
        {
            stack<int> stk;
            stk.push(K);
            cout << vis[curr] << "\n";
            while (g_prev[curr] != -1)
            {
                stk.push(g_prev[curr]);
                curr = g_prev[curr];
            }
            while (!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            return 0;
        }
        if (curr + 1 <= K && vis[curr + 1] > vis[curr] + 1)
        {
            q.push(curr + 1);
            vis[curr + 1] = vis[curr] + 1;
            g_prev[curr + 1] = curr;
        }
        if (curr - 1 >= 0 && vis[curr - 1] > vis[curr] + 1)
        {
            q.push(curr - 1);
            vis[curr - 1] = vis[curr] + 1;
            g_prev[curr - 1] = curr;
        }
        if (curr / 2 <= 50000 && vis[curr * 2] > vis[curr] + 1)
        {
            q.push(curr * 2);
            g_prev[curr * 2] = curr;
            vis[curr * 2] = vis[curr] + 1;
        }
    }
}