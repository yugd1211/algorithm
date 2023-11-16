#include <iostream>
#include <algorithm>
using namespace std;

int N, K;

// 순열
//  nPk = n!
//       -----
//      (n - k)!

// 조합
// nCk =  nPk
//      ------
//         k!
//    nCk = n!
//       --------
//      (n - k)!k!

int factorial(int n)
{
    int ans = 1;
    for (int i = 2; i <= n; i++)
        ans *= i;
    return ans;
}

int main()
{
    cin >> N;
    cin >> K;

    cout << factorial(N) / (factorial(N - K) * factorial(K));
    return 0;
}