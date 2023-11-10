#include <iostream>
using namespace std;

int N;
int arr[1002];

int main()
{
    cin >> N;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for (int i = 4; i <= 1000; i++)
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    cout << arr[N];
}