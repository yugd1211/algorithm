#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
	int answer = skill_trees.size();

	for (auto iter = skill_trees.begin(); iter != skill_trees.end(); iter++)
	{
		int adj[30];
		fill(adj, adj + 30, -1);
		string curr_skill_tree(*iter);

		for (int i = 0; i < skill.size(); i++)
		{
			char curr_skill = skill[i];
			for (int j = 0; j < curr_skill_tree.size(); j++)
				``
				{
					if (curr_skill == curr_skill_tree[j])
						adj[i] = j;
				}
		}

		for (int i = 0; i < skill.size(); i++)
		{
			if ((adj[i] == -1 && i + 1 < skill.size() && adj[i + 1] != -1) ||
				(adj[i] != -1 && i > 0 && adj[i] < adj[i - 1]))
			{
				answer--;
				break;
			}
		}
	}

	return answer;
}