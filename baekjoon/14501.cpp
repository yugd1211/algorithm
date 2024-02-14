#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define COST first
#define VAL second

// 런타임 발생 en이 N보다 커지는 상황을 인지는 했는데
// 코드를 수정하면서 해당 조건문을 지웠음
// 지금은 fill을 사용해서 최고수치로 dp를 수정할때마다 그 뒤의 값들을 해당 값으로
// 초기화하는데 사실은 dp를 기준으로 반복문을 돌려도 될거같다.
// 코드를 다 작성하고 dp의 중간의 값이 비는 경우가 생겨서
// 회피하려고 값을 집어넣어주긴했는데 만약 n이 커지면 시간 초과가 발생할 수도 있다.



// en, st, cost
vector<tuple<int, int, int>> t;
int dp[20];


int N;
int main()
{
	cin >> N;
	for (int i = 1 ; i <= N; i++)
	{
		int T, P;
		cin >> T >> P;
		t.push_back({i + T - 1, i, P});
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < N;i++)
	{
		int st, en, cost;
		tie(en, st, cost) = t[i];
		if (en > N)
			continue;
		if (dp[en] < cost + dp[st - 1] && dp[en - 1] < cost + dp[st - 1])
		{
			dp[en] = cost + dp[st - 1];
			fill(dp + en, dp + N + 1, cost + dp[st - 1]);
		}
	}
	cout << dp[N];
}
