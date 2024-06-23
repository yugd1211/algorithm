#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N;
int S[22][22];
int g_min = 2000000000;

int teamCountPlus(vector<int> team)
{
	int ans = 0;
	for (int i = 0; i < team.size(); i++)
	{
		for (int j = 0; j < team.size(); j++)
		{
			ans += S[team[i]][team[j]];
		}
	}
	return ans;
}

int compareTeam(vector<int> team1)
{
	vector<int> team2;
	for (int i = 0; i < N; i++)
	{
		if (find(team1.begin(), team1.end(), i) == team1.end())
			team2.push_back(i);
	}
	return abs(teamCountPlus(team1) - teamCountPlus(team2));
}

void pick_up(int curr, vector<int> team1)
{
	if (team1.size() >= N / 2)
	{
		g_min = min(compareTeam(team1), g_min);
		return;
	}
	if (curr >= N)
		return;
	pick_up(curr + 1, team1);
	team1.push_back(curr);
	pick_up(curr + 1, team1);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	pick_up(0, vector<int>());
	cout << g_min;
}