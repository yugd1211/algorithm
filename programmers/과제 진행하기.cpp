#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

// 새 과제부터 시작
// 진행중 새 과제가 있으면 진행중이던 과제를 큐에 넣는다.
// 과제를 진행한다.
// 과제가 끝나면 큐에서 꺼낸다.

vector<tuple<int, int, string>> v;
stack<tuple<int, int, string>> stk;

vector<string> solution(vector<vector<string>> plans)
{
	vector<string> answer;
	for (int i = 0; i < plans.size(); i++)
	{
		stringstream ss(plans[i][1]);
		int hour;
		int min;
		char tmp;
		ss >> hour;
		ss >> tmp;
		ss >> min;
		v.push_back({hour * 100 + min, stoi(plans[i][2]), plans[i][0]});
	}
	for (int i = 0; i < v.size(); i++)
	{
		int st, en;
		string name;
		tie(st, en, name) = v[i];
	}
	int index = 0;
	sort(v.begin(), v.end());
	// for (int i = 0; i < v.size(); i++)
	// {
	//     int st,en;
	//     string name;
	//     tie(st, en, name) = v[i];
	//     cout << st << ", " << en << ", " << name << endl;
	// }
	int curr_time = get<0>(*v.begin());
	stk.push(v[0]);
	while (1)
	{
		if (curr_time == 2400 || answer.size() == v.size())
			break;
		int st = -1, en = -1;
		string name;
		if (!stk.empty())
		{
			tie(st, en, name) = stk.top();
		}
		int end_time = st + en;
		if (st != -1 && end_time % 100 >= 60)
			end_time += 40;
		// cout << "curr = " << curr_time << ", end = " << end_time << "\n";
		if (curr_time >= end_time)
		{
			cout << name << endl;
			if (!stk.empty())
				stk.pop();
			answer.push_back(name);
		}
		cout << index << ", " << curr_time << ", " << get<0>(v[index + 1]) << endl;
		if (index < v.size() && curr_time >= get<0>(v[index + 1]))
		{
			cout << "index = " << index << "\n";
			index++;
			if (index < v.size())
				stk.push(v[index]);
		}

		curr_time++;
		if (curr_time % 100 >= 60)
			curr_time += 40;
	}
	// answer.erase(answer.end() - 1);
	return answer;
}