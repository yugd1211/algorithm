#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 8
vector<int> graph[N];
int indegree[N];

int main()
{
    queue<int> q;
    graph[1].push_back(2);
    indegree[2]++;
    graph[3].push_back(2);
    indegree[2]++;
    graph[3].push_back(4);
    indegree[4]++;
    graph[4].push_back(2);
    indegree[2]++;
    graph[4].push_back(5);
    indegree[5]++;
    graph[5].push_back(6);
    indegree[6]++;
    graph[7].push_back(5);
    indegree[5]++;
    for (int i = 1; i < N; i++)
        if (!indegree[i])
            q.push(i);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << char(curr + 'A' - 1);
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (--indegree[graph[curr][i]] == 0)
                q.push(graph[curr][i]);
        }
    }
}
