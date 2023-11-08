#include <iostream>
using namespace std;

int N, M;
int a[1000002];
int b[1000002];
int c[2000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
        cin >> a[i];
    for (int i = 0; i < M; i++)
        cin >> b[i];
    int addr = 0;
    int bddr = 0;
    for (int i = 0; i < N + M; i++)
    {
        if (addr == N)
            c[i] = b[bddr++];
        else if (bddr == M)
            c[i] = a[addr++];
        else if (a[addr] >= b[bddr])
            c[i] = b[bddr++];
        else
            c[i] = a[addr++];
    }
    for (int i = 0; i < N + M; i++)
        cout << c[i] << " ";

    return 0;
}