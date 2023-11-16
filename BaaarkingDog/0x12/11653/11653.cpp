#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
    cin >> N;
    int max = N;
    int prime = 2;
    while (N > 1)
    {
        if (prime * prime > max)
        {
            cout << N << "\n";
            return 0;
        }
        while (N % prime == 0)
        {
            N = N / prime;
            cout << prime << "\n";
        }
        prime++;
    }
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
    cin >> N;

    for (int prime = 2; prime * prime <= N; prime++)
    {
        while (N % prime == 0)
        {
            N = N / prime;
            cout << prime << "\n";
        }
    }
    if (N > 1)
        cout << N << "\n";
    return 0;
}