#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// 문자열을 순회하며 스택에 맨위에 저장돼있는것에 자신을 넣어보고,
// 해당 값이 폭발문자열과 순서와 배치가 같다면 해당 값을 저장
// 다르다면 따로 스택에 저장
// 반복

// 반례 : aaaaa
//        a
// answer : FRULA
// my_resurlt : aaaaa

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
		if (stk.empty())
		{
			stk.push(string(1, str[i]));
			continue;
		}
		string top = stk.top() + str[i];
		if (!bomb.compare(0, top.size(), top))
		{
			stk.pop();
			if (bomb.size() != top.size())
				stk.push(top);
		}
		else
			stk.push(string(1, str[i]));
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