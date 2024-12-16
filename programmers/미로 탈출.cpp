#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool vis[101][101];

int solution(vector<string> maps) 
{
    int answer = 0;
    memset(vis, 0, sizeof(vis));

    queue<tuple<int, int, int>> q;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'S')
                continue;
            q.push({i, j, 0});
            vis[i][j] = 1;
        }
    }
    while (!q.empty())
    { 
        int x, y, cost;
        tie(x, y, cost) = q.front(); 
        q.pop();
        
        if (maps[x][y] == 'L')
        {
            answer = cost;
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
                continue;
            if (vis[nx][ny] || maps[nx][ny] == 'X')
                continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny, cost + 1});
        }
    }

    if (answer == 0)
        return -1; 
    memset(vis, 0, sizeof(vis));
    while (!q.empty()) 
        q.pop(); 

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'L')
                continue;
            q.push({i, j, answer});
            vis[i][j] = 1;
        }
    }

    while (!q.empty())
    {
        int x, y, cost;
        tie(x, y, cost) = q.front(); 
        q.pop();

        if (maps[x][y] == 'E')
            return cost;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
                continue;
            if (vis[nx][ny] || maps[nx][ny] == 'X')
                continue;
            
            vis[nx][ny] = 1;
            q.push({nx, ny, cost + 1});
        }
    }

    return -1;
}
