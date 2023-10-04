#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack<int> stk;
    stack<int> ret;
    stack<int> big;
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        stk.push(num);
    }

    while (!stk.empty())
    {
        int num = stk.top();
        stk.pop();
        while (!big.empty() && big.top() < num)
            big.pop();
        if (!big.empty() && big.top() > num)
            ret.push(big.top());
        else
            ret.push(-1);
        big.push(num);
    }
    for (int i = 0; i < N; i++)
    {
        cout << ret.top() << " ";
        ret.pop();
    }
}