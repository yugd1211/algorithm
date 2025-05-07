#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define SHEEP 0
#define WOLF 1

// info : 노드별 0 = 양, 1 = 늑대
// edges : 부모, 자식

// 문제 풀이
// dfs로 노드 순회마다 전체탐색함
// 결점이 있는 방식으로 비트마스킹을 이용한 풀이가 있음
// https://blog.encrypted.gg/1029 확인해야함..

vector<int> g_graph[18];
vector<int> g_info;
int answer;

void dfs(int curr, int sheep, int wolf, queue<int> q)
{
	if (g_info[curr] == SHEEP)
		sheep++;
	else
		wolf++;
	if (sheep <= wolf)
		return;
	if (answer < sheep)
		answer = sheep;
	for (int i = 0; i < g_graph[curr].size(); i++)
		q.push(g_graph[curr][i]);
	int size = q.size();
	for (int i = 0; i < size; i++)
	{
		int nxt = q.front();
		q.pop();
		dfs(nxt, sheep, wolf, q);
		q.push(nxt);
	}
}

int solution(vector<int> info, vector<vector<int>> edges)
{
	g_info.assign(info.begin(), info.end());
	for (int i = 0; i < edges.size(); i++)
	{
		g_graph[edges[i][0]].push_back(edges[i][1]);
	}
	dfs(0, 0, 0, queue<int>());
	return answer;
}