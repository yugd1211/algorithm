#include <iostream>
using namespace std;

int N;
int arr[1000002];
int g_prev[1000002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    arr[1] = 0;
    g_prev[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        arr[i] = arr[i - 1] + 1;
        g_prev[i] = i - 1;
        if (!(i % 2) && arr[i / 2] < arr[i] - 1)
        {
            arr[i] = arr[i / 2] + 1;
            g_prev[i] = i / 2;
        }
        if (!(i % 3) && arr[i / 3] < arr[i] - 1)
        {
            arr[i] = arr[i / 3] + 1;
            g_prev[i] = i / 3;
        }
    }
    cout << arr[N] << "\n";
    cout << N << " ";
    while (g_prev[N])
    {
        cout << g_prev[N] << " ";
        N = g_prev[N];
    }
}