#include <iostream>
#include <algorithm>
using namespace std;

// 풀이법을 확인해봤다.
// m과 n의 최소공배수를 구하고 반복문에서 m만큼 더해가면 n을 나눈결과가 y인 경우가 있으면 이를 반환하고
// 없으면 -1을 반환

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y)
{
    if (x == m)
        x = 0;
    if (y == n)
        y = 0;
    int l = lcm(m, n);
    for (int i = x; i <= l; i += m)
    {
        if (i == 0)
            continue;
        if (i % n == y)
            return i;
    }
    return -1;
}

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << solve(M, N, x, y) << "\n";
    }
    return 0;
}