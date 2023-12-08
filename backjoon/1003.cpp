#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 기본적인 구조는 피보나치 함수와 비슷하다.
// 하지만 처음 딱 문제를 접했을때 바로 이해되진 않았고 노트에 적어보고 확인해보니 이해가 됐다.
// 문제에서 주는 피보나치 함수는 재귀적으로 피보나치 함수가 실행되고 n = 0 혹은 1일때는 해당 값을
// cnt 같은곳에 더해주면서 0 과 1까지 재귀적으로 내려간 횟수를 출력하는 문제이다.
// 말그대로 위처럼 재귀적으로 실행하면서 cnt를 올려주면 문제는 풀리지만 시간 제한에서 걸릴것이다.
// 기존의 피보나치를 dp를 활용해 푸는 것과 같이 초기 2개의 값의 0, 1이 나오는 횟수를 입력하고
// n - 1 + n - 2를 더해주면 됐다.

int N;
pair<int, int> dp[41];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for (int i = 2; i < 41; i++)
        dp[i] = {dp[i - 1].first + dp[i - 2].first,
                 dp[i - 1].second + dp[i - 2].second};
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cout << dp[num].first << " " << dp[num].second << "\n";
    }
}