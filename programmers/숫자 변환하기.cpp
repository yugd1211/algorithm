#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int vis[1000002];

int solution(int x, int y, int n)
{
    int answer = 0;
    queue<pair<int, int>> q;
    int i = 0;
    q.push({x, 0});
    fill(vis, vis + 1000001, 10000001);
    while (!q.empty())
    {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (curr > y)
            continue;
        if (curr == y)
            return cnt;
        
        if (curr + n <= 1000000 && vis[curr + n] > cnt + 1)
        {
            q.push({curr + n, cnt + 1});
            vis[curr + n] = cnt + 1;
        }
        if (curr * 2 <= 1000000 && vis[curr * 2] > cnt + 1)
        {
            q.push({curr * 2, cnt + 1});
            vis[curr * 2] = cnt + 1;
        }
        if (curr * 3 <= 1000000 && vis[curr * 3] > cnt + 1)
        {
            q.push({curr * 3, cnt + 1});
            vis[curr * 3] = cnt + 1;
        }
        
    }
    return -1;
}