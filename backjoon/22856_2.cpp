#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int lc[100001];
int rc[100001];
int p[100001];
int vis[100001];
int N;
long long ans;
long long cnt;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
        if (b != -1)
            p[b] = a;
        if (c != -1)
            p[c] = a;
    }
    stack<int> stk;
    stk.push(1);
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        if (!vis[curr])
        {
            if (cnt == N + N)
                break;
            else
                cnt++;
        }
        if (curr == -1)
            continue;
        ans++;
        if (vis[curr])
            continue;
        vis[curr] = 1;
        stk.push(p[curr]);
        stk.push(rc[curr]);
        stk.push(lc[curr]);
    }
    cout << ans - 1;
}