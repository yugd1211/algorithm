#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int A[2001];
int dp[2001][2001];

void fill_dp()
{
	for (int i = 1; i <= N; i++)
		dp[i][i] = 1;
	for (int i = 1; i <= N - 1; i++)
	{
		if (A[i] == A[i + 1])
			dp[i][i + 1] = 1;
	}
	for (int i = N - 2; i >= 1; i--)
	{
		for (int j = i + 2; j <= N; j++)
		{
			if (A[i] == A[j] && dp[i + 1][j - 1])
				dp[i][j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	fill_dp();
	cin >> M;
	while (M--)
	{
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}