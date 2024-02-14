#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

pair<int, int> p[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {y, x};
    }
    sort(p, p + N);
    for (int i = 0; i < N; i++)
        cout << p[i].second << " " << p[i].first << "\n";
}