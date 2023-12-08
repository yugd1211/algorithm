#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int ans = 0;
    int prev = 10000;
    int curr;
    for (int i = N - 1; i >= 0; i--)
    {
        curr = A[i];
        if (curr < prev)
            ans += curr;
    }
}