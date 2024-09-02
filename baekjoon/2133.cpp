#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[31];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	cin >> N;
	for (int i = 4; i <= N; i++)
	{
		if (i % 2)
			continue;
		for (int j = 0; j < i - 2; j++)
		{
			if (j % 2)
				continue;
			dp[i] += dp[j] * 2;
		}
		dp[i] += dp[i - 2] * dp[2];
	}
	cout << dp[N];
}