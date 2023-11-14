#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int N;
int rope[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> rope[i];
    
    sort(rope + 1, rope + N + 1);
    for (int i = 1; i <= N; i++)
        ans = max(ans, rope[i] * (N - i + 1));
    cout << ans;
    return 0;
}