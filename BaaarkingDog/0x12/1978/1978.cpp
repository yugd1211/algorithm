#include <iostream>
#include <algorithm>
using namespace std;

int N;
int notPrime;
int numbers[105];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    for (int i = 0; i < N; i++)
    {
        if (numbers[i] == 1)
            notPrime++;
        for (int j = 2; j * j <= numbers[i]; j++)
        {
            if (numbers[i] % j == 0)
            {
                notPrime++;
                break;
            }
        }
    }
    cout <<  N - notPrime;
    return 0;
}
