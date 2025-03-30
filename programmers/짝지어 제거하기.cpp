#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

// 시간초과 : N = 1000000
// 시간복잡도 N^2으로 시간초과발생
int solution(string s)
{
	for (int i = 0; i < s.size() - 1; i++)
	{
		if (!s.empty() && s[i] == s[i + 1])
		{
			s.erase(i, 2);
			i = -1;
		}
	}
	if (s.empty())
		return 1;
	return 0;
}

// stack을 이용해서 시간복잡도 N으로 해결
int solution(string s)
{
	stack<char> stk;
	stk.push(s[0]);
	for (int i = 1; i < s.size(); i++)
	{
		if (!stk.empty() && s[i] == stk.top())
			stk.pop();
		else
			stk.push(s[i]);
	}
	if (stk.empty())
		return 1;
	return 0;
}