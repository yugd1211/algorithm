#include <iostream>
#include <algorithm>
#include <vector>

// 일단 혼자의 힘으로는 적당한 풀이가 떠오르지 않았다.
// 다른 사람이 푼 풀이를 보고 풀었는데,
// DP 문제의 풀이는 혼자는 어떻게 쥐어짜도 잘 떠오르지 않는데 다른사람이 푼걸 보면 이렇게 쉬운 거였나....하는것 같다.
// 나만 이런건지 아직 문제를 많이 안풀어서 그런건지 모르겠다....

// 어쨋든 풀이는 이렇다.
// 1부터 목표 원(₩)까지의 dp를 채워나가는 방식이다.
// i원에서 해당 코인(j)을 뻇을때의 i - j원의 경우를 dp에 더해주는 방식이다.
// 코드로 보면 다음과 같다.
// dp[j] += dp[j - coin[i]];
// 이를 코인별로 반복해주면 된다.



using namespace std;
int N, K;

int coin[10001];
int dp[10001];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];
	sort(coin, coin + N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - coin[i] == 0)
				dp[j]++;
			if (j > coin[i])
				dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[K];
}