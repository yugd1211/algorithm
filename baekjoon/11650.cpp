#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
pair<int, int> p[100001];

// x, y를 둘다 정렬했기 때문에 pair를 선택했다.
// 이번 문제는 중복이 없었지만 중복이 있다해도 pair는 상관없다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i] = {x, y};
    }
    sort(p, p + N);
    for (int i = 0; i < N; i++)
        cout << p[i].first << " " << p[i].second << "\n";
}