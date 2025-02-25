#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations)
{
	vector<int> answer;
	multiset<int> s;

	for (int i = 0; i < operations.size(); i++)
	{
		stringstream ss(operations[i]);
		char oper;
		int num;
		ss >> oper;
		ss >> num;
		if (oper == 'I')
		{
			s.insert(num);
		}
		else
		{
			if (s.empty())
				continue;
			if (num == 1)
				s.erase(--s.end());
			else
				s.erase(s.begin());
		}
	}
	if (s.empty())
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		answer.push_back(*(--s.end()));
		answer.push_back(*s.begin());
	}
	return answer;
}