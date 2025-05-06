#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) 
{
    int N = prices.size();
    vector<int> answer(N);
    stack<int> stk;

    for (int i = 0; i < N; i++) 
    {
        while (!stk.empty() && prices[stk.top()] > prices[i]) 
        {
            int top = stk.top();
            stk.pop();
            answer[top] = i - top;
        }
        stk.push(i);
    }

    while (!stk.empty()) 
    {
        int top = stk.top();
        stk.pop();
        answer[top] = N - 1 - top;
    }

    return answer;
}