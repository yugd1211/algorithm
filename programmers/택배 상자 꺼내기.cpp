#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

bool isOdd(int num)
{
	if (num == 0)
		return false;
	return num % 2;
}

int solution(int n, int w, int num)
{
	int answer = 1;
	vector<stack<int>> stks(w);
	for (int i = 0; i < n; i++)
	{
		if (!isOdd(i / w))
			stks[i % w].push(i + 1);
		else
			stks[w - (i % w) - 1].push(i + 1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < stks.size(); i++)
		{
			if (stks[i].empty())
				return answer;
			if (stks[i].top() == num)
				return answer;
			stks[i].pop();
		}
		answer++;
	}

	return -1;
}