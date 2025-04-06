#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> sequence, int k)
{
	vector<int> answer;
	vector<pair<int, int>> ps;
	map<int, pair<int, int>> m;

	int lp = 0;
	int rp = 0;

	int curr = sequence[lp];
	while (lp <= sequence.size() - 1 && lp <= rp)
	{
		if (curr == k)
		{
			int cnt = rp - lp;
			if (m.find(cnt) == m.end())
				m.insert({cnt, {lp, rp}});
			curr -= sequence[lp++];
		}
		if (curr <= k && rp < sequence.size() - 1)
			curr += sequence[++rp];
		else
			curr -= sequence[lp++];
	}
	return {m.begin()->second.first, m.begin()->second.second};
}