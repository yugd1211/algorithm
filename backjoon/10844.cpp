#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
long long dp[101][11];
int main()
{
    cin >> N;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {

            if (j == 0)
                dp[i][0] = (dp[i - 1][1] % 1000000000);
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1] % 1000000000);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i <= 9; i++)
    {
        cnt = (cnt + dp[N][i]) % 1000000000;
    }
    cout << cnt;
}
