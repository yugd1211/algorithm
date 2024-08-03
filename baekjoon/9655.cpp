#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int dp[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	if (N % 2)
		cout << "SK";
	else
		cout << "CY";
}