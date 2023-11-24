#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;

class cmp
{
public:
    bool operator()(int a, int b)
    {
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > 0 && b < 0;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, cmp> pq;
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        if (n != 0)
            pq.push(n);
        else
        {
            if (pq.size())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
    }

    return 0;
}