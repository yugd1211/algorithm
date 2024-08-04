#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i < 1001; i++)
	{
		if (dp[i - 1] && dp[i - 3] && dp[i - 4])
			dp[i] = 0;
		else
			dp[i] = 1;
	}
	if (dp[N])
		cout << "SK";
	else
		cout << "CY";
}