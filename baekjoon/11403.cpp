#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int board[101][101];

vector<int> lst[101];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
            if (board[i][j])
                lst[i].push_back(j);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        queue<int> q;
        for (int j = 0; j < lst[i].size(); j++)
        {
            int dest = lst[i][j];
            board[i][dest] = 1;
            q.push(dest);
        }
        while (!q.empty())
        {
            int nxt = q.front();
            q.pop();
            for (int j = 0; j < lst[nxt].size(); j++)
            {
                int dest = lst[nxt][j];
                if (board[i][dest])
                    continue;
                board[i][dest] = 1;
                q.push(dest);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}