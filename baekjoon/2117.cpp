#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N; // 32767

long long dp[32768];
//

int main()
{
	cin >> N;
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 4;
	dp[6] = 6;

	for (int i = 7; i < 32768; i++)
	{
		dp[i] = dp[i - 1] + (i + 1) / 2 - 1;
	}
	cout << dp[N];
}