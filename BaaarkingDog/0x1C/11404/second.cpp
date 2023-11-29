#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int city[101][101];

// 3중 for문에서 so > st > en으로 바꿨다.
// 정확하게 이해하고 푼 방법은 아니지만
// 시작점을 처음에 모두 확인하고 끝내버리면 다른 곳에서 시작했을때에 대한 정보를 확인하지 못하지 않나
// 해서 경유지를 기준으로 모든 경우의 수를 대조해보는식으로 바꿨다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (i != j)
                city[i][j] = 200000001;
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        city[a][b] = min(cost, city[a][b]);
    }
    for (int so = 1; so <= N; so++)
    {
        for (int st = 1; st <= N; st++)
        {
            for (int en = 1; en <= N; en++)
            {
                city[st][en] = min(city[st][so] + city[so][en], city[st][en]);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (city[i][j] == 200000001)
                city[i][j] = 0;
            cout << city[i][j] << " ";
        }
        cout << "\n";
    }
}