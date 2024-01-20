#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
long long dp[1000002];

int main()
{

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	cin >> T;
	for (int i = 5; i < 1000001; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009; 
	}
	for (int i = 0; i < T; i++)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}
}