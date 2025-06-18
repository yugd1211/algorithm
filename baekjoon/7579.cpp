#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N; // 앱 개수 : 100
int M; // B 용량 : 10000000

int A[101]; // 용량 : 10000000
int C[101]; // 비용 : 100

int dp[101][10001]; // 비용 합계 최대 10000

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> C[i];

	int total = 0;
	for (int i = 0; i < N; i++)
		total += C[i];

	for (int j = 0; j <= total; j++)
	{
		if (j >= C[0])
			dp[0][j] = A[0];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= total; j++)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= C[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - C[i]] + A[i]);
		}
	}

	for (int j = 0; j <= total; j++)
	{
		if (dp[N - 1][j] >= M)
		{
			cout << j;
			break;
		}
	}
}