#include <string>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <tuple>
#include <sstream>

using namespace std;

void InputParser(vector<vector<string>> &input, vector<tuple<int, int, string>> &plan)
{
	for (int i = 0; i < input.size(); i++)
	{
		stringstream ss(input[i][1]);
		int st;
		ss >> st;
		st *= 60;
		char c;
		ss >> c;
		int minute;
		ss >> minute;
		st += minute;
		plan.push_back({st, stoi(input[i][2]), input[i][0]});
	}
}

vector<string> solution(vector<vector<string>> input)
{
	vector<tuple<int, int, string>> plan;
	stack<pair<int, string>> stk;
	vector<string> answer;

	InputParser(input, plan);
	int currTime = get<0>(plan[0]);

	sort(plan.begin(), plan.end());
	for (int i = 0; i < plan.size(); i++)
	{
		int st, en;
		string name;
		tie(st, en, name) = plan[i];
		if (i + 1 == plan.size() || st + en <= get<0>(plan[i + 1]))
		{
			currTime = st + en;
			answer.push_back(name);
		}
		else
		{
			currTime = get<0>(plan[i + 1]);
			stk.push({(st + en) - get<0>(plan[i + 1]), name});
		}

		while (!stk.empty())
		{
			if (i + 1 != plan.size() && currTime >= get<0>(plan[i + 1]))
				break;
			int remainingTime = stk.top().first;
			if (currTime + remainingTime <= get<0>(plan[i + 1]))
			{
				answer.push_back(stk.top().second);
				currTime += remainingTime;
				stk.pop();
			}
			else
			{
				stk.top().first -= get<0>(plan[i + 1]) - currTime;
				currTime = get<0>(plan[i + 1]);
				break;
			}
		}
	}
	while (!stk.empty())
	{
		answer.push_back(stk.top().second);
		stk.pop();
	}

	return answer;
}