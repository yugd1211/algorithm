#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

// 순열
//  nPk = n!
//       -----
//      (n - k)!

// 조합
// nCk =  nPk
//      ------
//         k!
//    nCk = n!
//       --------
//      (n - k)!k!

// 이번 문제는 이항 계수이지만 큰수를 다루기 때문에 10007로 나눈 나머지를 출력한다.
// 그렇기 때문에 모듈로 연산을 통해 10007로 나눠가면서 진행한다.
// 위의 조합 식에 모듈로 연산을 적용해도 되지만 큰 수일때 시간이 오래걸린다.

// 때문에 조합식 nCk = (n-1)Ck + (n-1)C(k-1)과 DP를 이용한다.
// 그래서 파스칼의 삼각형에 따라 유도가능
// dp에는 나머지값을 저장

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

int combination(int n, int k)
{
    return factorial(n) / (factorial(n - k) * factorial(k));
}

int dp[1002][1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> K;
    for (int i = 1; i <= 1000; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
        for (int j = 1; j <= 1000; j++)
        {
            if (j >= i)
                break;
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
        }
    }
    cout << dp[N][K];
    return 0;
}