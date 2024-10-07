#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int i = 0;
	while (i < s.size())
	{

		char firstC = s[i];
		int secCnt = 0;
		int cnt = 1;
		int j = i + 1;
		for (; j < s.size(); j++)
		{
			if (cnt == secCnt)
				break;
			if (s[j] == firstC)
				cnt++;
			else
				secCnt++;
		}
		answer++;
		i = j;
	}
	return answer;
}