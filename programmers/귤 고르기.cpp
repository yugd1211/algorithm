#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> gMap;

int solution(int k, vector<int> tangerine)
{
	int answer = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < tangerine.size(); i++)
		gMap[tangerine[i]]++;

	for (auto iter = gMap.begin(); iter != gMap.end(); iter++)
		v.push_back({iter->second, iter->first});
	sort(v.begin(), v.end(), greater<pair<int, int>>());
	for (auto nxt : v)
	{
		k -= nxt.first;
		answer++;
		if (k <= 0)
			break;
	}
	return answer;
}