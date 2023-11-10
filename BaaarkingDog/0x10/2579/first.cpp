#include <iostream>
using namespace std;

// 현재의 계단을 연속으로 올라온건지 건너뛰고 밟은건지를 체크하면서 최대값을 구하고
// 그 중 더 큰값을 출력함

int N;
int stairs[303];
int d[303][3];

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stairs[i];
    if (N == 1)
    {
        cout << stairs[1];
        return 0;
    }
    d[1][1] = stairs[1];
    d[1][2] = 0;
    d[2][1] = stairs[2];
    d[2][2] = stairs[1] + stairs[2];
    for (int i = 0; i < 301; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + stairs[i];
        d[i][2] = d[i - 1][1] + stairs[i];
    }
    cout << max(d[N][1], d[N][2]);
    return 0;
}
