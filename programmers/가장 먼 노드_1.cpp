#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> edges[20001];
int dist[20001];

// 시간 초과
// 아마도 이미 탐색한 정점을 계속 탐색하는 부분에서 시간 초과발생하는듯함

int solution(int n, vector<vector<int>> input_edge)
{
	int answer = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

	for (int i = 0; i < input_edge.size(); i++)
	{
		edges[input_edge[i][0]].push_back(input_edge[i][1]);
		edges[input_edge[i][1]].push_back(input_edge[i][0]);
	}
	for (int i = 0; i < edges[1].size(); i++)
	{
		dist[edges[1][i]] = 1;
		pq.push({1, 1, edges[1][i]});
	}
	while (!pq.empty())
	{
		int st, en, de;
		tie(de, st, en) = pq.top();
		pq.pop();
		for (int i = 0; i < edges[en].size(); i++)
		{
			if (dist[edges[en][i]] && dist[edges[en][i]] < de + 1)
				continue;
			dist[edges[en][i]] = de + 1;
			pq.push({de + 1, en, edges[en][i]});
		}
	}
	int max_value = 0;
	for (int i = 2; i <= n; i++)
		max_value = max(max_value, dist[i]);
	for (int i = 2; i <= n; i++)
	{
		if (max_value == dist[i])
			answer++;
	}

	return answer;
}