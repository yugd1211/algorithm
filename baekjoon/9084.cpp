#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int dp[10001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> T;
	while (T--)
	{
		int N;
		vector<int> coin;
		int dest;

		cin >> N;
		fill(dp, dp + 10001, 0);
		dp[0] = 1;
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;
			coin.push_back(n);
		}
		cin >> dest;

		for (int i = 0; i < N; i++)
			for (int j = coin[i]; j <= dest; j++)
				dp[j] += dp[j - coin[i]];

		cout << dp[dest] << "\n";
	}
}
