#include <iostream>
using namespace std;

long N, K;
long coins[12];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    long total = K;
    int cnt = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (total >= coins[i])
        {
            while (total >= coins[i])
            {
                total -= coins[i];
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
