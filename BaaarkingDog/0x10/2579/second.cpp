#include <iostream>
using namespace std;

// 역으로 생각해서 밟지 않은 수들의 최소값을 구하고 총합에서 그 수를 빼는 방식
// 마지막은 무조건 밟아야 하니 그전과, 그 전의전 계단을 밟지 않았을때 더 작은 값을 수용

int N;
int stairs[303];
int d[303];
int total;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
        total += stairs[i];
    }
    if (N <= 2)
    {
        cout << total;
        return 0;
    }
    d[1] = stairs[1];
    d[2] = stairs[2];
    d[3] = stairs[3];
    for (int i = 4; i <= N; i++)
    {
        d[i] = min(d[i - 2], d[i - 3]) + stairs[i];
    }
    cout << total - min(d[N - 1], d[N - 2]);
    return 0;
}
