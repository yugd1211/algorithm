#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
long long dp[1000002];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i < 1000001; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	cout << dp[N];
}