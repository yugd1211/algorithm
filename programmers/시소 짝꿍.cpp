#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 시간 초과 발생
bool CheckBalance(double a, double b)
{
	if (a == b)
		return true;
	for (int i = 2; i <= 4; i++)
	{
		double unitA = a / i;
		for (int j = 2; j <= 4; j++)
		{
			double unitB = b / j;
			if (unitA == unitB)
				return true;
		}
	}
	return false;
}

long long solution(vector<int> ws)
{
	long long answer = 0;
	sort(ws.begin(), ws.end());
	for (int i = 0; i < ws.size(); i++)
	{
		for (int j = i + 1; j < ws.size(); j++)
		{
			if (ws[i] < (double)ws[j] / 4)
				break;
			if (CheckBalance(ws[i], ws[j]))
				answer++;
			else
				continue;
		}
	}
	return answer;
}