#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int N, M;
deque<int> dq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int ans = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        if (dq.size() / 2 < dq.size() - (dq.end() - find(dq.begin(), dq.end(), n)))
        {
            while (dq.front() != n)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        }
        else
        {
            while (dq.front() != n)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        }
    }
    cout << ans;
}