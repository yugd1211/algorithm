#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool isCorrect(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            stk.push(s[i]);
        }
        else
        {
            char c = stk.top();
            stk.pop();
            if ((s[i] == ']' && c == '[') ||
                (s[i] == ')' && c == '(') ||
                (s[i] == '}' && c == '{')
               )
            {
                continue;
            }
            return false;
        }
    }
    if (!stk.empty())
        return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[0];
        s.erase(s.begin(), s.begin() + 1);
        s.push_back(c);
        answer += isCorrect(s);
    }
    return answer;
}