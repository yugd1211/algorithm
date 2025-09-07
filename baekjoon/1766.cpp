#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int MAX = 10000000;

// N : 32000
int N;
// M : 100000
int M;

// ex) N : 4
// 4 > 2
// 3 > 1

vector<int> edges[32001];
vector<int> p[32001];
bool vis[32001];
priority_queue<int, vector<int>, greater<int>> pq;

bool CheckParentVisit(int n)
{
	for (int i = 0; i < p[n].size(); i++)
	{
		if (vis[p[n][i]] == false)
			return false;
	}
	return true;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// 입력
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		p[v].push_back(u);
	}

	// 루트 노드 우선순위큐에 삽입
	for (int i = 1; i <= N; i++)
	{
		if (p[i].empty())
			pq.push(i);
	}

	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();
		if (vis[top])
			continue;
		vis[top] = true;
		cout << top << " ";
		for (int i = 0; i < edges[top].size(); i++)
		{
			if (vis[edges[top][i]])
				continue;
			// 모든 부모를 방문해야 추가
			if (CheckParentVisit(edges[top][i]))
				pq.push(edges[top][i]);
		}
	}
}