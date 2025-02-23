#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit)
{
	int answer = 0;
	sort(people.begin(), people.end());

	int st = 0;
	int en = people.size();
	while (st < --en)
	{
		if (people[st] + people[en] <= limit)
		{
			st++;
		}
		answer++;
	}
	if (st == en)
		answer++;
	return answer;
}