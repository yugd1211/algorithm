#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    // multimap<int, int> meet;
    vector<tuple<int, int> >meet;
    for (int i = 0; i < N; i++)
    {
        int _end;
        int _start;
        cin >> _start;
        cin >> _end;
        meet.push_back({_end, _start});
    }
    sort(meet.begin(), meet.end());
    int start = 0;
    for (int i = 0; i < N; i++)
    {
        if (get<1>(meet[i]) >= start) 
        {
            cnt++;
            start = get<0>(meet[i]);
        }
    }

    cout << cnt;
    return 0;
}