#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

std::stack<int> stk;
int stkIdx = 1;
std::vector<char> printVec;

void errorExit()
{
    std::cout << "NO\n";
    exit(0);
}

void printChar(char c)
{
    std::cout << c << "\n";
}

using namespace std;

int main()
{
    int cnt = 0;
    cin >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        int num = 0;
        cin >> num;
        if (num > cnt)
            errorExit();
        while (stk.empty() || stk.top() < num)
        {
            stk.push(stkIdx++);
            printVec.push_back('+');
        }
        if (stk.top() != num)
            errorExit();
        stk.pop();
        printVec.push_back('-');
    }
    for_each(printVec.begin(), printVec.end(), printChar);
}