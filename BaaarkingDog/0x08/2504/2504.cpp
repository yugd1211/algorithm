#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
int main()
{
    std::stack<char> stk;
    int ret = 0;
    string str; cin >> str;
    int two = 0;
    int three = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' && str[i + 1] == ')')
        {
            int scale = 1;
            if (two)
                scale = pow(2, two);
            if (three)
                scale *= pow(3, three);
            ret += scale * 2;
            i++;
        }
        else if (str[i] == '[' && str[i + 1] == ']')
        {
            int scale = 1;
            if (two)
                scale = pow(2, two);
            if (three)
                scale *= pow(3, three);
            ret += scale * 3;
            i++;
        }
        else if (str[i] == '(')
        {
            stk.push('(');
            two++;
        }
        else if (str[i] == ')')
        {
            if (stk.empty() || stk.top() != '(')
            {
                cout << 0;
                return 0;
            }
            stk.pop();
            two--;
        }
        else if (str[i] == '[')
        {
            stk.push('[');
            three++;
        }
        else if (str[i] == ']')
        {
            if (stk.empty() || stk.top() != '[')
            {
                cout << 0;
                return 0;
            }
            stk.pop();
            three--;
        }
    }
    if (!stk.empty())
    {
        cout << 0;
        return 0;
    }
    cout << ret;
}