#include <iostream>
#include <algorithm>

using namespace std;

int N;
int K;
int W[108];
int V[108];
int dp[108][100008];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> W[i];
        cin >> V[i];
    }
    // 모든 물건에 대한 반복문을 돌려야 하기때문에 N개 만큼 반복문을 실행함
    for (int i = 1; i <= N; i++)
    {
        // 무게에 대한 반복문
        // 낮은 무게부터 채워나가야 큰 무게에서 작은 무게들을 가져다 쓸 수 있음
        // K = 최대 무게일때 현재 물건의 무게를 뺐을때 해당 하는 물건들의 합을 미리 구해둬야함
        // 그렇기 때문에 모든 물건들에 대한 무게와 낮은 무게에서의 최대치를 구해나가는것
        for (int j = 1; j <= K; j++)
        {
            // 현재 무게가 현재 물건의 무게보다 크면
            if (j >= W[i])
            // 이전 물건들의 최대치이거나,
            // 현재 물건의 무게 + 현재의 물건의 무게를 뺀 무게에서 만들 수 있는 물건의 무게의 최대치
                dp[i][j] = max(dp[i - 1][j], V[i] + dp[i - 1][j - W[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
    return 0;
}