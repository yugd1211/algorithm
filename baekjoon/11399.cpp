#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int adj[1001];
int N;
int ans;
int dp[1001];

void plusAns(int n)
{
	ans += n;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> adj[i];
	sort(adj, adj + N);
	dp[0] = adj[0];
	for (int i = 1; i < N; i++)
		dp[i] = dp[i - 1] + adj[i];
	for_each(dp, dp + N, plusAns);
	cout << ans;
}