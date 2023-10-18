#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    int num; cin >> num;
    std::queue<int> que;
    cin.ignore();
    for (int i = 0; i < num; i++)
    {
        string str;
        getline(cin, str);
        stringstream ss(str);
        ss >> str;
        if (!str.compare("push"))
        {
            int n;
            ss >> n;
            que.push(n);
        }
        else if (!str.compare("pop"))
        {
            if (!que.empty())
            {
                cout << que.front() << endl;
                que.pop();
            }
            else    
                cout << "-1\n";
        }
        else if (!str.compare("size"))
        {
            cout << que.size() << "\n";
        }
        else if (!str.compare("empty"))
        {
            cout << que.empty() << "\n";
        }
        else if (!str.compare("front"))
        {
            if (!que.empty())
                cout << que.front() << "\n";
            else    
                cout << "-1\n";
        }
        else if (!str.compare("back"))
        {
            if (!que.empty())
                cout << que.back() << "\n";
            else    
                cout << "-1\n";
        }
    }
}