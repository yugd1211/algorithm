#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, k;

vector<vector<int>> arr;
int visit[110001];
int cmin;

int main()
{
    // 오른으로 돌면 2463 <- 왼으로 돌면 2463 -> 위아래는 1356

    // 앞 0 왼 1 아래 2 오른 3 뒤 4 위 5

    scanf("%d%d%d", &n, &k, &m);
    arr.resize(n + m + 1);
    cmin = 1000000;
    for (int i = 0; i < m; i++)
    {
        int asdf[1001];
        for (int j = 0; j < k; j++)
        {
            // 1~n,n+1~n+m
            int tmp;
            scanf("%d", &tmp);
            arr[(i + n + 1)].push_back(tmp);
            arr[tmp].push_back(i + n + 1);
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    while (q.size() != 0)
    {
        int station = q.front().first;
        int depth = q.front().second;

        q.pop();
        if (visit[station] != 0)
            continue;
        visit[station] = depth;

        for (int i = 0; i < arr[station].size(); i++)
        {
            int next = arr[station][i];
            if (next == n)
            {
                cmin = min(cmin, depth + 1);
                cout << cmin;
                return 0;
            }
            if (next > n)
            {
                q.push(make_pair(next, depth));
            }
            else
            {
                q.push(make_pair(next, depth + 1));
            }
        }
    }

    cout << "-1";
    // 바닥은 3번
}