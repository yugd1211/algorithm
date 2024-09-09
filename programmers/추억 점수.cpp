#include <string>
#include <vector>
#include <iostream>
using namespace std;

// name, yearning = 이름에 대한 그리움 점수, photo = 이름들
vector<int> solution(vector<string> name,
					 vector<int> yearning,
					 vector<vector<string>> photo)
{
	vector<int> answer;
	for (int k = 0; k < photo.size(); k++)
	{
		int ans = 0;
		for (int i = 0; i < photo[k].size(); i++)
		{
			for (int j = 0; j < name.size(); j++)
			{
				if (photo[k][i] == name[j])
				{
					ans += yearning[j];
				}
			}
		}
		answer.push_back(ans);
	}
	return answer;
}