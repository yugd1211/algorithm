#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int city[101][101];

// 3중 for문에서 st > so > en 이 잘못된거 같다.

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
    for (int st = 1; st <= N; st++)
    {
        for (int so = 1; so <= N; so++)
        {
            for (int en = 1; en <= N; en++)
            {
                city[st][en] = min(city[st][so] + city[so][en], city[st][en]);
            }
        }
    }
    cout << "====ans====\n";
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << city[i][j] << " ";
        cout << "\n";
    }
}