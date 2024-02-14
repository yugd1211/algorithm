#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int fix[42];
int dp[42];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i < 41; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	fix[0] = 0;
	fix[M + 1] = N + 1;
	for (int i = 1; i <= M; i++)
		cin >> fix[i];
	sort(fix, fix + M + 2);
	int ans = 1;
	for (int i = 1; i < M + 2; i++)
	{
		int size = fix[i] - fix[i - 1] - 1;
		if (size)
			ans *= dp[size];
	}
		cout << ans;
}