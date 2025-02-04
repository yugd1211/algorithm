#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int D, P;
vector<pair<int, int>> v;
int dp[100002];

// DP 배낭문제로 update를 D부터 top-down방식으로 진행했다.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> D >> P;
	dp[0] = 1000000000;
	for (int i = 0; i < P; i++)
	{
		int L, C;
		cin >> L >> C;
		v.push_back({L, C});
	}

	for (int i = 0; i < P; i++)
	{
		int cost, val;
		cost = v[i].first;
		val = v[i].second;
		for (int j = D; j >= cost; j--)
			dp[j] = max(dp[j], min(dp[j - cost], val));
	}
	cout << dp[D];
}