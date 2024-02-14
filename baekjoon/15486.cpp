#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define ST first
#define COST second

using namespace std;
int N;

// 배열의 인덱스를 end로 잡고 해당 벡터에 시작점과 코스트를 묶은 pair를 추가시키고
// dp를 순회하면서 해당 dp 인덱스에 끝나는 상담을 확인하며 dp를 업데이트 하는 방법

// st, cost
vector <pair<int, int>> p[1500001];
int dp[1500001];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		//int st, en, cost;
		int T , P;
		cin >>T >> P;
		if (i + T - 1 <= N)
			p[i + T - 1].push_back({i ,P});
	}
	for (int i = 1; i <= N; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 0; j < p[i].size(); j++)
		{
			if (dp[i] < dp[p[i][j].ST - 1] + p[i][j].COST)
				dp[i] = dp[p[i][j].ST - 1] + p[i][j].COST;
		}
	}
	cout << dp[N];
}