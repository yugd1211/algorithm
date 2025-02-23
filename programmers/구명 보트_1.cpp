#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

// set을 활용한 방법 : 시간초과
int solution(vector<int> people, int limit)
{
	int answer = 0;

	sort(people.begin(), people.end());
	multiset<int> s;
	for (int i = 0; i < people.size(); i++)
		s.insert(people[i]);
	while (!s.empty())
	{
		multiset<int>::iterator msiter = s.begin();
		for (auto iter = s.upper_bound(limit - *s.begin()); iter != s.begin(); iter--)
		{
			if (iter == s.end())
				continue;
			if (*iter + *s.begin() <= limit)
			{
				msiter = iter;
				break;
			}
		}
		if (msiter != s.begin())
			s.erase(msiter);
		s.erase(s.begin());
		answer++;
	}
	return answer;
}
