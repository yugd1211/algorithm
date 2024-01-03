#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int N;
int board[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char n;
            cin >> n;
            if (n == '1')
                board[i][j] = -1;
        }
    }
    vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == -1)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                int cnt = 1;
                while (!q.empty())
                {
                    int x = q.front().X;
                    int y = q.front().Y;
                    q.pop();
                    if (x < 0 || y < 0 || x >= N || y >= N)
                        continue;
                    if (board[x][y] != -1)
                        continue;
                    board[x][y] = cnt++;
                    for (int i = 0; i < 4; i++)
                        q.push({x + dx[i], y + dy[i]});
                }
                vec.push_back(cnt);
            }
        }
    }
    cout << vec.size() << "\n";
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] - 1 << "\n";
}