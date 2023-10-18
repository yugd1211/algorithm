#include <iostream>
#include <deque>

using namespace std;
int main()
{
    std::deque<int> deq;
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        string str; cin >> str;
        if (!str.compare("push_back"))
        {
            int n; cin >> n;
            deq.push_back(n);
        }
        if (!str.compare("push_front"))
        {
            int n; cin >> n;
            deq.push_front(n);
        }
        if (!str.compare("pop_front"))
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }
        if (!str.compare("pop_back"))
        {
            if (deq.empty())
                cout << "-1\n";
            else
            {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }
        if (!str.compare("size"))
            cout << deq.size() << "\n";
        if (!str.compare("empty"))
            cout << deq.empty() << "\n";
        if (!str.compare("front"))
        {
            if (deq.empty())
                cout << "-1\n";
            else
                cout << deq.front() << "\n";
        }
        if (!str.compare("back"))
        {
            if (deq.empty())
                cout << "-1\n";
            else
                cout << deq.back() << "\n";
        }
    }
}