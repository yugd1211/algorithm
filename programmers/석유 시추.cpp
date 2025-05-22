#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

#define MAX_VAL 501

using namespace std;
int N, M;
int vis[MAX_VAL][MAX_VAL];
int areaCount[MAX_VAL * MAX_VAL];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void ClearVis()
{
    for (int i = 0; i < MAX_VAL;i++)
        fill(vis[i], vis[i] + MAX_VAL, 0);
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    N = land.size();
    M = land[0].size();
    int area = 1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (land[i][j] == 1 && vis[i][j] == 0)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();
                    if (vis[x][y])
                        continue;
                    vis[x][y] = area;
                    areaCount[area]++;
                    
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        
                        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                            continue;
                        if (land[nx][ny] == 0 || vis[nx][ny])
                            continue;
                        q.push({nx, ny});
                    }
                }
                area++;
            }
        }
    }
    for (int y = 0; y < M; y++)
    {
        set<int> s;
        for (int x = 0; x < N; x++)
        {
            if (vis[x][y])
                s.insert(vis[x][y]);
        }
        int yTotal = 0;
        for (auto iter : s)
            yTotal += areaCount[iter];
        answer = max(answer, yTotal);
    }
    return answer;
}