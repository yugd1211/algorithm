#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

// DP로 풀이
// 제곱근이 정수일 경우 해당 dp는 1로 고정
// 제곱근이 정수가 아닐때는 이전 DP를 순회하며 dp[i] + dp[i - j]의 값을 확인하며 dp를 수정하며 순회

int N;
int dp[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 1;
	for (int i = 4; i < N + 1; i++)
	{
		if ((int)sqrt(i) * (int)sqrt(i) == i)
			dp[i] = 1;
		else
		{
			for (int j = 1; j < i / 2 + 1; j++)
			{
				if (!dp[i] || dp[i] > dp[i - j] + dp[j])
					dp[i] = dp[i - j] + dp[j];
			}
		}
	}
	cout << dp[N];
}