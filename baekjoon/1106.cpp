#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int C; // 1000
int N; // 20
int dp[1101];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> C >> N;

	fill(dp, dp + 1101, 1000000000);
	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		int u, v;
		cin >> u >> v;

		for (int j = v; j <= C + 100; j++)
		{
			dp[j] = min(dp[j], dp[j - v] + u);
		}
	}

	int res = dp[C];
	for (int i = C + 1; i <= C + 100; i++)
	{
		res = min(res, dp[i]);
	}

	cout << res;
}