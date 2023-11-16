#include <iostream>
#include <algorithm>
using namespace std;

// 일단 생각나는 대로 구현해봤지만 틀렸다.

int g_input;
int main()
{
    cin >> g_input;
    for (int i = 0; i < g_input; i++)
    {
        int M, N, x, y;
        cin >> M >> N >> x>> y;
        long long curr = 1;
        while (1)
        {
            if (curr % M == x && curr % N == y)
            {
                cout << curr << "\n";
                break;
            }
            if (curr % M == 0 && curr % N == 0 && curr > M * M && curr > N * N)
            {
                cout << -1 << "\n";
                break;
            }
            curr++;
        }
    }
    return 0;
}