#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int answer = 0;

int solution(vector<int> numbers, int target)
{
	queue<pair<int, int>> q;

	q.push({numbers[0], 0});
	q.push({-numbers[0], 0});
	while (!q.empty())
	{
		int curr = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (depth == numbers.size() - 1)
		{
			if (curr == target)
				answer++;
			continue;
		}
		q.push({curr + numbers[depth + 1], depth + 1});
		q.push({curr - numbers[depth + 1], depth + 1});
	}
	return answer;
}