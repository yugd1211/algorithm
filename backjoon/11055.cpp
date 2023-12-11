#include <iostream>
#include <algorithm>

using namespace std;

// LIS 알고리즘 문제로
// dp에 자신보다 작은 수들 + 자신을 더한값을 업데이트하는 방식

int N;
int A[1001];
int dp[1001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        dp[i] = A[i];
    }
    int ans = 0;
    int prev = 10000;
    for (int curr = 0; curr < N; curr++)
    {
        for (int j = 0; j < curr; j++)
        {
            if (A[j] < A[curr])
                dp[curr] = max(dp[j] + A[curr], dp[curr]);
        }
    }
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}