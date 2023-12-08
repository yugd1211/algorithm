#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int s[1000001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> s[i];
    sort(s, s + N);
    for (int i = N - 1; i >= 0; i--)
        cout << s[i] << "\n";
}