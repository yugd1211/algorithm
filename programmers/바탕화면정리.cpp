#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
	vector<int> answer;
	int lux = -1, luy = -1;
	int rdx = -1, rdy = -1;

	for (int i = 0; i < wallpaper.size(); i++)
	{
		if (wallpaper[i].find('#') != string::npos)
		{
			lux = i;
			break;
		}
	}
	for (int i = wallpaper.size() - 1; i >= 0; i--)
	{
		if (wallpaper[i].find('#') != string::npos)
		{
			rdx = i;
			break;
		}
	}

	for (int i = 0; i < wallpaper[0].size(); i++)
	{
		bool b = false;
		for (int j = 0; j < wallpaper.size(); j++)
		{
			if (wallpaper[j][i] == '#')
			{
				luy = i;
				b = true;
				break;
			}
		}
		if (b == true)
			break;
	}

	for (int i = wallpaper[0].size() - 1; i >= 0; i--)
	{
		bool b = false;
		for (int j = wallpaper.size() - 1; j >= 0; j--)
		{
			if (wallpaper[j][i] == '#')
			{
				rdy = i;
				b = true;
				break;
			}
		}
		if (b == true)
			break;
	}
	answer.push_back(lux);
	answer.push_back(luy);
	answer.push_back(rdx + 1);
	answer.push_back(rdy + 1);
	return answer;
}