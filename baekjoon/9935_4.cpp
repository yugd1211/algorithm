#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 이전과 같은 문제를 해결하고자 스택에 char로 하나씪 넣고
// 폭탄문자열을 뒤집어서
// 맨끝부터 폭탄문자열과 비교하고 만약 틀리면 이전값들 다시 스택에 넣는 방식으로 진행

void SetIO()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}

bool FindStringInStack(stack<char> &stk, const string &str, vector<char> &contain)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (stk.top() == str[i])
		{
			contain.push_back(stk.top());
			stk.pop();
		}
		else
			return false;
	}
	return true;
}

int main()
{
	SetIO();
	string str, bomb, result;
	cin >> str >> bomb;
	stack<char> stk;

	reverse(bomb.begin(), bomb.end());
	for (int i = 0; i < str.size(); i++)
	{
		stk.push(str[i]);
		if (stk.size() < bomb.size())
			continue;
		vector<char> tmp;
		if (FindStringInStack(stk, bomb, tmp) == false)
		{
			for (int i = tmp.size() - 1; i >= 0; i--)
				stk.push(tmp[i]);
		}
	}

	while (!stk.empty())
	{
		result.push_back(stk.top());
		stk.pop();
	}
	reverse(result.begin(), result.end());
	if (result.empty())
		cout << "FRULA";
	else
		cout << result;
}