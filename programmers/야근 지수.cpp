#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works)
{
	long long answer = 0;
	sort(works.begin(), works.end(), greater<>());
	while (n)
	{
		int point = works[0] - 1;
		for (int i = 0; i < works.size(); i++)
		{
			if (n > 0 && point < works[i])
			{
				works[i]--;
				n--;
			}
		}
	}

	for (int i = 0; i < works.size(); i++)
		if (works[i] < 0)
			works[i] = 0;

	for (int i = 0; i < works.size(); i++)
		answer += works[i] * works[i];
	return answer;
}