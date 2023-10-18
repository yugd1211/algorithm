#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num; cin >> num;
    std::queue<int> que;
    while (num--)
    {
        string str;
        cin >> str;
        if (str == "push")
        {
            int n;
            cin >> n;
            que.push(n);
        }
        else if (str =="pop")
        {
            if (!que.empty())
            {
                cout << que.front() << "\n";
                que.pop();
            }
            else    
                cout << "-1\n";
        }
        else if (str =="size")
        {
            cout << que.size() << "\n";
        }
        else if (str =="empty")
        {
            cout << que.empty() << "\n";
        }
        else if (str =="front")
        {
            if (!que.empty())
                cout << que.front() << "\n";
            else    
                cout << "-1\n";
        }
        else
        {
            if (!que.empty())
                cout << que.back() << "\n";
            else    
                cout << "-1\n";
        }
    }
}
