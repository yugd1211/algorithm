#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// 기존의 풀이는 이미 탐색한 정점에 대해서도 계속 순회를 했기 때문에 특정 경우에 vertex^2의 시간복잡도를 가질 수 있다.
// 때문에 탐색을 끝마진 간선은 제거하는 방식으로 진행했다.
// 이 때 vector를 사용하면 제거에 대한 시간복잡도가 n이기 때문에 오히려 제거에 대한 시간복잡도로 n^2을 사용하기 때문에 set으로 대체했다.

set<int> edges[20001];
int dist[20001];

int solution(int n, vector<vector<int>> input_edge)
{
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < input_edge.size(); i++)
	{
		edges[input_edge[i][0]].insert(input_edge[i][1]);
		edges[input_edge[i][1]].insert(input_edge[i][0]);
	}
	for (auto iter : edges[1])
	{
		dist[iter] = 1;
		edges[iter].erase(1);
		pq.push({1, iter});
	}
	while (!pq.empty())
	{
		int st, de;
		tie(de, st) = pq.top();
		pq.pop();
		for (auto iter : edges[st])
		{
			if (dist[iter])
				continue;
			dist[iter] = de + 1;
			edges[iter].erase(st);
			pq.push({de + 1, iter});
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