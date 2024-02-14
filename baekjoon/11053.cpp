#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1001];
int dp[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    fill(dp, dp + N, 1);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int curr = 0; curr < N; curr++)
    {
        for (int j = 0; j < curr; j++)
        {
            if (A[curr] > A[j])
                dp[curr] = max(dp[curr], dp[j] + 1);
        }
    }
    int ans = 1;
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}