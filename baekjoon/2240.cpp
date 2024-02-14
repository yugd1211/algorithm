#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제 풀이
// DP로 접근해서 문제를 풀었다.
// 자두가 떨어지는 시간마다 모든 횟수에 대해 연산을 한다.
// 0부터 W까지 DP 배열을 업데이트하는데 그 방법은 다음과 같다.
// 일단 현재 횟수의 이전 시간까지 먹을 수 있는 자두 갯수 + 현재시간에 현재위치에 떨어지는 자두를 업데이트한다.
// 그러면 이전횟수의 값이 그대로 담기거나, +1이 담기게 될것이다.
// 그리고 '이전횟수의 반대되는 위치의 값 + 현재위치에 자두가 떨어지면 그것도 포함'이랑 현재위치의 값을 비교해서 업데이트한다.

int T, W;
int board[2][1001];
int vis[2][1001][31];

void printBoard()
{
    cout << "=======print board========\n";
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << vis[k][i][j] << " ";
            }
            cout << " ";
        }
        cout << "\n";
    }
    cout << "==========================\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T >> W;
    for (int i = 1; i <= T; i++)
    {
        int n;
        cin >> n;
        board[n - 1][i] = 1;
    }
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (j == 0 && k == 1)
                    continue;
                vis[k][i][j] = vis[k][i - 1][j] + board[k][i];
                if (j == 0)
                    continue;
                vis[k][i][j] = max(vis[k][i][j], vis[(k + 1) % 2][i - 1][j - 1] + board[k][i]);
            }
        }
    }
    // printBoard();
    cout << max(vis[0][T][W], vis[1][T][W]);
}