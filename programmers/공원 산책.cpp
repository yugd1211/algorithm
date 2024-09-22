#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes)
{
	vector<int> answer;
	int x = 0, y = 0;
	for (int i = 0; i < park.size(); i++)
	{
		for (int j = 0; j < park.size(); j++)
		{
			if (park[i][j] == 'S')
			{
				x = i;
				y = j;
			}
		}
	}
	for (auto nxt : routes)
	{
		int nx = x;
		int ny = y;
		char c = nxt[0];
		int m = nxt[2] - '0';
		if (c == 'N')
		{
			nx -= m;
			bool b = false;
			if (nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size())
				continue;
			for (int i = 0; i <= m; i++)
			{
				if (park[x - i][y] == 'X')
				{
					b = true;
					break;
				}
			}
			if (b)
				continue;
		}
		else if (c == 'S')
		{
			nx += m;
			bool b = false;
			if (nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size())
				continue;
			for (int i = 0; i <= m; i++)
			{
				if (park[x + i][y] == 'X')
				{
					b = true;
					break;
				}
			}
			if (b)
				continue;
		}
		else if (c == 'W')
		{
			ny -= m;
			bool b = false;
			if (nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size())
				continue;
			for (int i = 0; i <= m; i++)
			{
				if (park[x][y - i] == 'X')
				{
					b = true;
					break;
				}
			}
			if (b)
				continue;
		}
		else if (c == 'E')
		{
			ny += m;
			bool b = false;
			if (nx < 0 || ny < 0 || nx >= park.size() || ny >= park[0].size())
				continue;
			for (int i = 0; i <= m; i++)
			{
				if (park[x][y + i] == 'X')
				{
					b = true;
					break;
				}
			}
			if (b)
				continue;
		}
		x = nx;
		y = ny;
	}
	answer.push_back(x);
	answer.push_back(y);
	return answer;
}