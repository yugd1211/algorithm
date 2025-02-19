#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<int> Split(string str, char delimiter)
{
	stringstream ss(str);
	vector<int> ret;

	string s;
	while (getline(ss, s, delimiter))
	{
		int num = stoi(s);
		ret.push_back(num);
	}
	return ret;
}

vector<int> solution(string s)
{
	vector<int> answer;
	map<int, vector<int>> m;

	s.erase(s.begin());
	s.erase(s.size() - 1);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '{')
		{
			int j = i;
			i++;
			while (++j < s.size())
			{
				if (s[j] == '}')
					break;
			}
			string str = s.substr(i, j - i);
			vector<int> v = Split(str, ',');
			m[v.size()] = v;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		vector<int> curr = iter->second;
		for (int i = 0; i < curr.size(); i++)
		{

			if (find(answer.begin(), answer.end(), curr[i]) == answer.end())
			{
				answer.push_back(curr[i]);
				break;
			}
		}
	}
	return answer;
}
