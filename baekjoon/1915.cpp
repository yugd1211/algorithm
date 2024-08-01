#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제 풀이
// 사각형의 크기를 dp에 담아준다
// 점화식은 사각형의 왼쪽, 위, 왼쪽위 대각선의 값중 min값 + 1이다.

int N, M;
int board[1001][1001];
int dp[1001][1001];
int ans;

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
}

void printDP()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (!board[i][j])
				continue;
			dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans * ans;
}