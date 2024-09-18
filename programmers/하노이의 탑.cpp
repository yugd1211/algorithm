#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk[3];
vector<pair<int, int>> vec;

void moveTop(int curr, int dest)
{
	stk[dest].push(stk[curr].top());
	stk[curr].pop();
	vec.push_back({curr + 1, dest + 1});
}

void hanoi(int N, int curr, int dest)
{
	int nx;
	if (N <= 0)
		return;
	if (curr == 0)
	{
		if (dest == 1)
			nx = 2;
		else
			nx = 1;
	}
	else if (curr == 1)
	{
		if (dest == 2)
			nx = 0;
		else
			nx = 2;
	}
	else
	{
		if (dest == 1)
			nx = 0;
		else
			nx = 1;
	}
	hanoi(N - 1, curr, nx);
	moveTop(curr, dest);
	hanoi(N - 1, nx, dest);
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> answer;
	for (int i = n; i > 0; i--)
		stk[0].push(i);
	hanoi(n, 0, 2);
	for (int i = 0; i < vec.size(); i++)
	{
		vector<int> tmp;
		tmp.push_back(vec[i].first);
		tmp.push_back(vec[i].second);
		answer.push_back(tmp);
	}
	return answer;
}