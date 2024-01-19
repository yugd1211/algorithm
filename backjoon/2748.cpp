#include <iostream>
#include <algorithm>
using namespace std;

long long dp[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
}