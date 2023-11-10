#include <iostream>
using namespace std;

int N;
int cost[1002][3];
int d[1002][3];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> cost[i][j];
    d[0][0] = cost[0][0];
    d[0][1] = cost[0][1];
    d[0][2] = cost[0][2];
    for (int i = 1; i < N; i++)
        for (int j = 0; j < 3; j++)
            d[i][j] = min(d[i - 1][(j + 1) % 3], d[i - 1][(j + 2) % 3]) + cost[i][j];

    cout << min(d[N - 1][0], min(d[N - 1][1], d[N - 1][2]));
    return 0;
}