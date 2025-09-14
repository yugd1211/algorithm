#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int GetCost(int l, int r)
{
	if (l == 0)
		return 2;
	if (l == r)
		return 1;
	if (abs(l - r) == 1 || abs(l - r) == 3)
		return 3;

	return 4;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	// input
	vector<int> steps;
	int n;
	while (cin >> n && n != 0)
	{
		steps.push_back(n);
	}

	// init
	vector<vector<int>> dp(5, vector<int>(5, INT_MAX));
	vector<vector<int>> newDp(5, vector<int>(5, INT_MAX));

	dp[0][0] = 0;

	// dp
	for (int step = 0; step < steps.size(); step++)
	{
		int target = steps[step];

		// 새로운 DP 배열 초기화
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				newDp[i][j] = INT_MAX;
			}
		}

		for (int left = 0; left < 5; left++)
		{
			for (int right = 0; right < 5; right++)
			{
				if (dp[left][right] == INT_MAX)
					continue;

				if (target != right)
				{
					int cost = dp[left][right] + GetCost(left, target);
					newDp[target][right] = min(newDp[target][right], cost);
				}

				if (target != left)
				{
					int cost = dp[left][right] + GetCost(right, target);
					newDp[left][target] = min(newDp[left][target], cost);
				}
			}
		}

		dp = newDp;
	}

	int result = INT_MAX;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			result = min(result, dp[i][j]);

	cout << result << endl;
	return 0;
}