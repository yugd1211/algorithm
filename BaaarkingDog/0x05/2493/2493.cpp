#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
int main()
{
    int N = 0;
    int pos;
    std::stack<int> stk;
    std::stack<int> ret;

    cin >> N;
    pos = N;
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        cin >> num;
        stk.push(num);
    }
    for (int i = 0; i < N; i++)
    {
        int curr = stk.top();
        stk.pop();
        pos--;
        std::stack<int> tmp;
        while (1)
        {
            if (stk.empty())
            {
                ret.push(0);
                break;
            }
            int leftTop = stk.top();
            if (leftTop > curr)
            {
                ret.push(pos);
                break;
            }
            else
            {
                tmp.push(leftTop);
                stk.pop();
                pos--;
            }
        }
        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
            pos++;
        }
    }
    while (!ret.empty())
    {
        std::cout << ret.top() << " ";
        ret.pop();
    }
}