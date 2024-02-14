#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int N, Q;
int adj[500001];
bool attr[500001];
int curr = 1;
set<int> s;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            s.insert(i);
            attr[i] = 1;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int q;
        cin >> q;
        if (q == 1)
        {
            int n;
            cin >> n;
            if (attr[n])
                s.erase(n);
            else
                s.insert(n);
            attr[n] = !attr[n];
        }
        else if (q == 2)
        {
            int x;
            cin >> x;
            curr = (curr + x) % N;
            if (curr == 0)
                curr = N;
        }
        else
        {
            if (s.empty())
                cout << -1 << "\n";
            else if (s.lower_bound(curr) != s.end())
                cout << *s.lower_bound(curr) - curr << "\n";
            else
                cout << *s.lower_bound(1) + N - curr << "\n";
        }
    }
}