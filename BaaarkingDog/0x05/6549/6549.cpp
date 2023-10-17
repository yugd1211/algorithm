#include <iostream>
#include <stack>

using namespace std;
int numArr[100002] = {};
int main()
{
    while (1)
    {
            std::stack<int> stk;
            int cnt; 
            cin >> cnt;
            if (cnt == 0)
                return 0;
            int ret = 0;
            bzero(numArr, sizeof(int) * 100002);
            for (int i = 1; i <= cnt; i++)
                cin >> numArr[i];
            stk.push(0);
            for (int i = 1; i <= cnt + 1; i++)
            {
                while (!stk.empty() && numArr[stk.top()] > numArr[i])
                {
                    int curr = stk.top();
                    stk.pop();
                    ret = max(ret, numArr[curr] * (i - 1 - stk.top()));
                }
                stk.push(i);
            }
            cout << ret << "\n";
    }
}