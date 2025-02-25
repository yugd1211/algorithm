#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int vis[201];
int answer = 0;

void dfs(vector<vector<int>> &computers, int curr)
{
	for (int i = 0; i < computers[curr].size(); i++)
	{
		if (vis[i] || computers[curr][i] == 0)
			continue;
		vis[i] = 1;
		dfs(computers, i);
	}
}

int solution(int n, vector<vector<int>> computers)
{
	for (int i = 0; i < computers.size(); i++)
	{
		for (int j = 0; j < computers[i].size(); j++)
		{
			if (vis[j] || computers[i][j] == 0)
				continue;
			answer++;
			dfs(computers, j);
		}
	}

	return answer;
}