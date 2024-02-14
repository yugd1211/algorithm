#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long dp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;

    for (int i = 7; i < 101; i++)
        dp[i] = dp[i - 1] + dp[i - 5];
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cout << dp[num] << "\n";
    }
}
