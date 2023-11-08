#include <iostream>
using namespace std;
int n;
int req[2000004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        req[1000000 + k]++;
    }
    for (int i = 0; i <= 2000000; i++)
        for (int j = 0; j < req[i]; j++)
            cout << i - 1000000 << "\n";
    return 0;
}