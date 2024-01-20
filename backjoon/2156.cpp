#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[10002][2];
int board[10002];
int N;

void printDp()
{
	for (int i = 0 ; i < N; i++)	
	{
		for (int j = 0 ; j < 2; j++)
			cout <<  dp[i][j] << " ";
		cout << "\n";
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> board[i];
	dp[0][0] = board[0];
	dp[1][1] = board[0];
	dp[1][0] = board[0] + board[1];
	for (int i = 2; i < N; i++)
	{
		int prev = i - 1;
		dp[i][1] = max(dp[prev][0], dp[prev][1]);
		dp[i][0] = max(dp[prev][1] + board[i], dp[prev - 1][1] + board[prev] + board[i]);
	}
	//printDp();
	cout << max(dp[N - 1][0], dp[N - 1][1]);
}