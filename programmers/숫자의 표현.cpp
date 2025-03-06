#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n)
{
	int answer = 0;

	if (n == 0 || n == 1)
		return 1;
	int curr = 1;
	int lastNum = 1;
	for (int i = 2; i < 10001; i++)
	{
		curr += i;
		while (curr > n)
			curr -= lastNum++;
		if (curr == n)
			answer++;
	}
	return answer;
}