#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section)
{
	int answer = 1;
	sort(section.begin(), section.end());
	int st = section[0] + m;
	while (!section.empty())
	{
		if (st > section[0])
		{
			section.erase(section.begin(), section.begin() + 1);
			continue;
		}
		st = section[0] + m;
		answer++;
	}
	return answer;
}