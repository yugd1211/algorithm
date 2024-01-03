#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int F, S, G, U, D;
int vis[1000001];
// 총 층수
// 현재 위치
// goal 위치
// up 층수
// down 층수

int main()
{
    queue<int> q;
    cin >> F >> S >> G >> U >> D;
    q.push(S);
    vis[S] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == G)
        {
            cout << vis[G] - 1;
            return 0;
        }
        if (curr + U <= F && !vis[curr + U])
        {
            vis[curr + U] = vis[curr] + 1;
            q.push(curr + U);
        }
        if (curr - D >= 1 && !vis[curr - D])
        {
            vis[curr - D] = vis[curr] + 1;
            q.push(curr - D);
        }
    }
    cout << "use the stairs";
}
