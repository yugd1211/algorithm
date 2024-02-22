#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// LCS 알고리즘 문제
// 참고 :  https://www.youtube.com/watch?v=EAXDUxVYquY
//

string A;
string B;

int dp[1001][1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	getline(cin, A);
	getline(cin, B);
	A.insert(A.begin(), 0);
	B.insert(B.begin(), 0);
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 1; j < B.size(); j++)
		{
			if (A[i] == B[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	cout << dp[A.size() - 1][B.size() - 1];
}