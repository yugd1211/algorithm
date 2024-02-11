#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
long long dp[100001][3];
long long arr[100001][3];

void clearArr()
{
	for (int i = 0; i < 100001; i++)
	{
		fill(dp[i], dp[i] + 3, 300000000000);
		fill(arr[i], arr[i] + 3, 300000000000);
	}
}

int main()
{
	while (1)
	{
		T++;
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		clearArr();
		for (int i = 0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

		dp[0][1] = arr[0][1];
		for (int i = 0; i < n; i++)
		{
			if (i == n - 1)
			{
				if (dp[i][1] > dp[i][0] + arr[i][1])
					dp[i][1] = dp[i][0] + arr[i][1];
				break;
			}
			for (int j = 0; j < 3; j++)
			{
				if (i == 0 && j == 0)
					continue;
				if (j == 0)
				{
					if (dp[i][1] > dp[i][0] + arr[i][1])
						dp[i][1] = dp[i][0] + arr[i][1];
					if (dp[i + 1][0] > dp[i][0] + arr[i + 1][0])
						dp[i + 1][0] = dp[i][0] + arr[i + 1][0];
					if (dp[i + 1][1] > dp[i][0] + arr[i + 1][1])
						dp[i + 1][1] = dp[i][0] + arr[i + 1][1];
				}
				else if (j == 1)
				{
					if (dp[i][2] > dp[i][1] + arr[i][2])
						dp[i][2] = dp[i][1] + arr[i][2];
					if (dp[i + 1][2] > dp[i][1] + arr[i + 1][2])
						dp[i + 1][2] = dp[i][1] + arr[i + 1][2];
					if (dp[i + 1][1] > dp[i][1] + arr[i + 1][1])
						dp[i + 1][1] = dp[i][1] + arr[i + 1][1];
					if (dp[i + 1][1] > dp[i][1] + arr[i + 1][0])
						dp[i + 1][0] = dp[i][1] + arr[i + 1][0];
				}
				else
				{
					if (dp[i + 1][2] > dp[i][2] + arr[i + 1][2])
						dp[i + 1][2] = dp[i][2] + arr[i + 1][2];
					if (dp[i + 1][1] > dp[i][2] + arr[i + 1][1])
						dp[i + 1][1] = dp[i][2] + arr[i + 1][1];
				}
			}
		}
		cout << T << ". " << dp[n - 1][1] << "\n";
	}
}