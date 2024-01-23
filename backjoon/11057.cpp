#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long dp[1001][1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++)
				dp[i][j] += dp[i - 1][k];
			dp[i][j] %= 10007;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += dp[N][i];
	
	cout << ans % 10007;
}