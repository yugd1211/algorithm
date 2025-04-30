#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool IsDistancing(vector<string> &board)
{
    int n = board.size();
    int m = board[0].size();
    
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'P')
            {
                bool vis[6][6];
                queue<tuple<int, int, int>> q;
                for (int i = 0; i < 6; i++)
                    fill(vis[i], vis[i] + 6, false);
                bool isNot = false;
                q.push({i, j, 0});
                vis[i][j] = true;
                while (!q.empty())
                {
                    int x, y, cost;
                    tie(x, y, cost) = q.front();
                    q.pop();
                    if (cost + 1 == 3)
                        continue;
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (vis[nx][ny] == true)
                            continue;
                        if (board[nx][ny] == 'P')
                            return false;
                        if (board[nx][ny] == 'X')
                            continue;
                        vis[nx][ny] = true;
                        q.push({nx, ny, cost + 1});
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) 
{
    vector<int> answer;
    // x, y, cost
    for (auto board : places)
    {
        if (IsDistancing(board))
            answer.push_back(1);
        else 
            answer.push_back(0);
    }
    return answer;
}