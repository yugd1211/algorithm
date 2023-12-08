#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[91];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 2;
    for (int i = 4; i < 91; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    cout << arr[N];
}