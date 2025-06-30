#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define MAX 1000000000
#define COLORS 3
int N;
int dp[COLORS][COLORS][1001];
int adj[COLORS][1001];

int main()
{
	cin.tie();
	ios::sync_with_stdio(0);
	int answer = MAX;

	// input
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < COLORS; j++)
			cin >> adj[j][i];

	// init
	for (int i = 0; i < COLORS; i++)
		for (int j = 0; j < COLORS; j++)
			fill(dp[i][j], dp[i][j] + 1001, MAX);
	for (int i = 0; i < COLORS; i++)
		dp[i][i][0] = adj[i][0];

	// dp fill
	for (int i = 1; i < N; i++)
	{
		for (int curr = 0; curr < COLORS; curr++)
		{
			for (int prev = 0; prev < COLORS; prev++)
			{
				if (curr == prev)
					continue;
				for (int j = 0; j < COLORS; j++)
					dp[j][curr][i] = min(dp[j][curr][i], dp[j][prev][i - 1] + adj[curr][i]);
			}
		}
	}

	// find answer
	for (int i = 0; i < COLORS; i++)
	{
		for (int j = 0; j < COLORS; j++)
		{
			if (i == j)
				continue;
			answer = min(answer, dp[i][j][N - 1]);
		}
	}
	cout << answer;
}