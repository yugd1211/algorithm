#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land)
{
	int answer = 0;
	vector<vector<int>> dp(land);

	for (int i = 1; i < land.size(); i++)
	{
		for (int j = 0; j < land[i].size(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (j == k)
					continue;
				dp[i][j] = max(dp[i][j], land[i][j] + dp[i - 1][k]);
			}
		}
	}

	for (int i = 0; i < 4; i++)
		answer = max(answer, dp[dp.size() - 1][i]);
	return answer;
}