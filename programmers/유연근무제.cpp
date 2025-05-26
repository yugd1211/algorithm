#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday)
{
	int answer = 0;

	// 월요일 시작
	for (int i = 0; i < timelogs.size(); i++)
	{
		rotate(timelogs[i].begin(), timelogs[i].end() - (startday - 1), timelogs[i].end());
	}

	for (int i = 0; i < schedules.size(); i++)
	{
		schedules[i] += 10;
		if (schedules[i] % 100 >= 60)
		{
			schedules[i] += 100;
			schedules[i] -= 60;
		}
	}

	for (int currIdx = 0; currIdx < timelogs.size(); currIdx++)
	{
		vector<int> curr = timelogs[currIdx];
		bool isOver = false;
		for (int i = 0; i < curr.size() - 2; i++)
		{
			if (curr[i] > schedules[currIdx])
			{
				isOver = true;
				break;
			}
		}
		if (!isOver)
			answer++;
	}

	return answer;
}