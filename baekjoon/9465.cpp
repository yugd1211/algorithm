#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int main()
{
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N; cin >> N;
		int board[2][100001];
		int dp[2][100001];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int i = 0; i < 2; i++)
			{
				if (j == 0)
					dp[i][j] = board[i][j];
				else if (j == 1)
					dp[i][j] = dp[(i + 1) % 2][j - 1] + board[i][j];
				else
				{
					dp[i][j] = dp[(i + 1) % 2][j - 1] + board[i][j];
					dp[i][j] = max(dp[i][j], dp[i][j - 2] + board[i][j]);
					dp[i][j] = max(dp[i][j], dp[(i + 1) % 2][j - 2] + board[i][j]);
				}
			}
		}
		int ans = max(dp[0][N - 1], dp[1][N - 1]);
		cout << ans << "\n";
	}
}