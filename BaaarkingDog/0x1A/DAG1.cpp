// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// vector<int> graph[8];

// int main()
// {
//     graph[1].push_back(2);
//     graph[3].push_back(2);
//     graph[3].push_back(4);
//     graph[4].push_back(2);
//     graph[4].push_back(5);
//     graph[5].push_back(6);
//     graph[7].push_back(5);
//     for (int i = 0; )
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 8
int graph[N][N];
int vis[N];

bool getIsParent(int child)
{
    for (int i = 1; i < N; i++)
    {
        if (graph[i][child])
            return 1;
    }
    return 0;
}

int main()
{
    queue<int> q;
    graph[1][2] = 1;
    graph[3][2] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    graph[4][5] = 1;
    graph[5][6] = 1;
    graph[7][5] = 1;
    for (int i = 1; i < N; i++)
    {
        bool pg = 0;
        for (int j = 1; j < N; j++)
        {
            if (graph[j][i])
            {
                pg = 1;
                break;
            }
        }
        if (!pg)
            q.push(i);
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (vis[curr])
            continue;
        if (getIsParent(curr))
            q.push(curr);
        else
        {
            cout << char(curr + 'A' - 1);
            vis[curr] = 1;
            for (int i = 1; i < N; i++)
            {
                if (graph[curr][i])
                {
                    q.push(i);
                    graph[curr][i] = 0;
                }
            }
        }
    }
}