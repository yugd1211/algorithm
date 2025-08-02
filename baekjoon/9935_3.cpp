#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 문자열을 순회하며 스택에 맨위에 저장돼있는것에 자신을 넣어보고,
// 해당 값이 폭발문자열과 순서와 배치가 같다면 해당 값을 저장
// 다르다면 따로 스택에 저장
// 반복

// 이유 : if (!bomb.compare(0, top.size(), top))
// 여기서 처음부터 확인하려하기 떄문에
// 맨끝의 문자열이 폭탄문자열일때 처리하지 못함

// 반례 :aaabaaaabb
// 		aab
// answer : a
// my_answer : aaab

void SetIO()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main()
{
	SetIO();
	string str, bomb, result;
	cin >> str >> bomb;
	stack<string> stk;

	for (int i = 0; i < str.size(); i++)
	{
		string top;
		if (stk.empty())
			top = str[i];
		else
		{
			top = stk.top() + str[i];
		}
		if (!bomb.compare(0, top.size(), top))
		{
			if (bomb.size() != top.size())
			{
				if (!stk.empty())
					stk.pop();
				stk.push(top);
			}
			else if (!stk.empty())
				stk.pop();
		}
		else
		{
			stk.push(string(1, str[i]));
		}
	}

	vector<string> vec;
	while (!stk.empty())
	{
		vec.push_back(stk.top());
		stk.pop();
	}
	reverse(vec.begin(), vec.end());

	if (vec.empty())
		cout << "FRULA";

	for (auto iter : vec)
		cout << iter;
}