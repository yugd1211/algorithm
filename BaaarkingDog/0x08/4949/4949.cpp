#include <iostream>
#include <stack>

using namespace std;
int main()
{
    while (1)
    {
        std::stack<char> stk;
        bool ok = true;
        string line;
        getline(cin, line);
        if (!line.compare("."))
            return 0;
        else
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '(')
                    stk.push('(');
                else if (line[i] == ')')
                {
                    if (stk.empty() || stk.top() != '(')
                    {
                        ok = false;
                        break;
                    }
                    stk.pop();
                }
                else if (line[i] == '[')
                    stk.push('[');
                else if (line[i] == ']')
                {
                    if (stk.empty() || stk.top() != '[')
                    {
                        ok = false;
                        break;
                    }
                    stk.pop();
                }
                else
                {
                }
            }
            if (ok && !stk.empty())
                ok = false;
            if (ok)
                cout << "yes\n";
            else
                cout << "no\n";
        }
    }
}