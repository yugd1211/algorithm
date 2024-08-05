#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> A;
int dp[5001];
int d = 1000000;

// 일단 혼자 힘으로 풀지는 못했다.
// 얼추 방향까지는 잡았는데 구체적인 구현에서 막혀서 다른 사람의 풀이를 보고 풀었다.

// 문제 풀이
// 현재 수를 가지고 조합 할 수 있는 수는 2가지이다.
// 1. 현재 수와 이전 수를 각 각 따로 할 경우 이전 값을 그대로 계승한다.
// 2. 현재 수와 이전 수를 조합했을때 26이하일 경우 이를 값에 더해준다.
// 하지만 현재 수가 0일 경우 무조건 이전 수 뒤에 붙기 때문에 값은 변하지 않는다.
// 1 번의 경우 DP[i] = DP[i - 1] 으로 이전 값을 그대로 계승한다.
// 2 번은 1번 + DP[i] += DP[i - 2] 이다.

void input()
{
	int index = 0;
	A.push_back(0);
	string s;
	getline(cin, s);
	for (auto iter = s.begin(); iter != s.end(); iter++)
		A.push_back(*iter - '0');
	if (A[1] == 0)
	{
		cout << 0;
		exit(0);
	}
}

void printA()
{
	for (auto iter = A.begin(); iter != A.end(); iter++)
		cout << *iter << ", ";
	cout << "\n";
}

void printDP()
{
	for (int i = 1; i < A.size(); i++)
		cout << dp[i] << ", ";
	cout << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < A.size(); i++)
	{
		if (A[i] >= 1 && A[i] <= 9)
			dp[i] = dp[i - 1] % d;
		if (A[i - 1] != 0 || A[i - 1] * 10 + A[i] > 26)
			continue;
		dp[i] = (dp[i] + dp[i - 2]) % d;
	}
	cout << dp[A.size() - 1];
}
