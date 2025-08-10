#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dp[100001];

// DP를 활용한 동전 교환 문제 - 경우의 수 구하기
// 점화식: dp[j] = dp[j] + dp[j - money[i]]
// dp[j]: j원을 만드는 경우의 수
// dp[j - money[i]]: (j - money[i])원을 만드는 경우의 수에 money[i] 동전을 추가
// 1 -> N까지 순회하며 이전 동전들만 있을떄 만들 수 있는 경우의 수 + 현재 동전을 뺏을때의 값을 만들 수 있는 경우의 수를 더하는 방식

/*
동작 예시: money = [1, 2, 5], n = 5인 경우

1. 동전 1원 처리 후:
   dp[0]=1, dp[1]=1, dp[2]=1, dp[3]=1, dp[4]=1, dp[5]=1
   (모든 금액을 1원 동전으로만 만드는 경우 = 1가지씩)

2. 동전 2원 처리 후:
   dp[0]=1, dp[1]=1, dp[2]=2, dp[3]=2, dp[4]=3, dp[5]=3
   (2원 동전을 추가로 사용할 수 있는 경우들이 추가됨)

3. 동전 5원 처리 후:
   dp[0]=1, dp[1]=1, dp[2]=2, dp[3]=2, dp[4]=3, dp[5]=4
   (5원 동전을 사용하는 경우가 추가됨: dp[5] += dp[0] = 1)

최종 답: 4 (1+1+1+1+1, 1+1+1+2, 1+2+2, 5)
*/

int solution(int n, vector<int> money) 
{
    dp[0] = 1;
    
    for (int i = 0; i < money.size(); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j - money[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
            }
        }
    }
    return dp[n] % 1000000007;
}