#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
set<string> vis;

int solution(string begin, string target, vector<string> words)
{
	queue<pair<string, int>> q;
	q.push({begin, 0});
	vis.insert(begin);
	while (!q.empty())
	{
		string curr = q.front().first;
		int d = q.front().second;
		q.pop();
		if (curr == target)
			return d;

		vis.insert(curr);
		auto iter = find(words.begin(), words.end(), curr);
		if (iter != words.end())
			words.erase(iter);
		for (int i = 0; i < words.size(); i++)
		{
			if (vis.find(words[i]) != vis.end())
				continue;
			int sameCount = 0;
			for (int j = 0; j < curr.size(); j++)
			{
				if (curr[j] == words[i][j])
					sameCount++;
			}
			if (sameCount == curr.size() - 1)
				q.push({words[i], d + 1});
		}
	}

	return 0;
}
