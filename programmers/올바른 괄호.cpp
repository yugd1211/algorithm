#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

bool solution(string s)
{
	stack<char> stk;

	for (auto iter : s)
	{
		if (iter == '(')
			stk.push('(');
		else
		{
			if (stk.empty() || stk.top() == ')')
				return false;
			stk.pop();
		}
	}
	if (stk.empty())
		return true;
	return false;
}