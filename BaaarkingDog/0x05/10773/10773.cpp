#include <iostream>
#include <stack>

using namespace std;

int main()
{
    std::stack<int> stk;
    int K = 0;
    
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num = 0;
        cin >> num;
        if (num == 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(num);
        }
    }
    int ret = 0;
    while (!stk.empty())
    {
        ret += stk.top();
        stk.pop();
    }
    std::cout << ret;
}