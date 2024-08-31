#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 111111111

int N, K;
int coin[105];
int dp[100005];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	dp[0] = 0;
	for (int i = 1; i <= K; i++)
		dp[i] = INF;
	for (int i = 1; i <= K; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i - coin[j] < 0)
				continue;
			dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		}
	}
	cout << (dp[K] >= INF ? -1 : dp[K]);
}