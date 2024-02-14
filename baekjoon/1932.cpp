#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> vec[501];
vector<int> dp[501];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int num;
            cin >> num;
            vec[i].push_back(num);
            dp[i].push_back(num);
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j - 1 < 0)
                dp[i][j] = dp[i][j] + dp[i - 1][j];
            else if (j == i)
                dp[i][j] = dp[i][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(dp[N - 1][i], ans);
    cout << ans;
    return 0;
}