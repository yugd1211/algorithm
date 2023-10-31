#include <iostream>
#include <stack>

using namespace std;
int main()
{
    std::stack<char> stk;
    int ret = 0;
    string str; cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' && str[i + 1] == ')')
        {
            i++;
            ret += stk.size();
        }
        else if (str[i] == '(')
        {
            ret++;
            stk.push('(');
        }
        else if (str[i] == ')')
            stk.pop();
    }
    cout << ret;
}