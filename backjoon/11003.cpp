#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#define X first
#define Y second
using namespace std;

int N, L;
// 값, 위치
deque<pair<int, int>> dq;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        while (!dq.empty() && n < dq.back().X)
            dq.pop_back();
        dq.push_back({n, i});
        while (i - dq.front().Y >= L)
            dq.pop_front();
        cout << dq.front().X << " ";
    }
}
