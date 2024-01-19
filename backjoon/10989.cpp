#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;

int num[10001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        num[n]++;
    }
    for (int i = 0; i < 10001; i++)
    {
        for (int j = 0; j < num[i]; j++)
            cout << i << "\n";
    }
}