#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int main()
{
    cin >> N;
    vector<int> divisor;
    for (int i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            if (N / i == i)
                divisor.push_back(i);
            else
            {
                divisor.push_back(i);
                divisor.push_back(N / i);
            }
        }
    }
    return 0;
}