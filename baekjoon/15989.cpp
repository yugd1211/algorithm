#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int dp[4][10002];

// n < 10000
int main()
{
    dp[1][0] = 1;
    dp[2][0] = 1;
    dp[3][0] = 1;

    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[3][1] = 0;

    dp[1][2] = 1;
    dp[2][2] = 1;
    dp[3][2] = 0;

    
    dp[1][3] = 1;
    dp[2][3] = 1;
    dp[3][3] = 1;
    for (int i = 4; i <= 10000; i++)
    {
        dp[1][i] = 1;
        dp[2][i] = dp[2][i - 2] + 1;
        dp[3][i] = dp[3][i - 3] + dp[2][i - 3] + 1;
    }


    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n; cin >> n;
        cout << dp[3][n] + dp[2][n] + dp[1][n] << "\n";
    }
}