#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

// 문제 풀이
// 이 문제는 위상 정렬을 사용하여 해결할 수 있다.
// 1. input을 입력받을 때, 앞의 숫자를 부모 노드로 하여 간선을 연결해준다. 이때 자식 노드의 indegree를 하나 증가시킨다.
// 2. 모든 입력을 다 받은 후, indegree가 0인 노드를 찾아 queue에 넣어준다.
// 3. queue에 있는 노드들은 현재 부모 간선이 없는 노드들이므로, 해당 노드를 ans에 추가하고, 해당 노드들의 자식 노드들의 indegree를 감소시킨다.
// 4. 3번을 queue가 빌때까지 반복하고, ans에 모든 노드들이 담겨있는지 확인하고 ans를 순서대로 출력하거나, 0을 출력한다.

int N, M;
int indegree[1001];
vector<int> v[1001];
queue<int> q;
vector<int> ans;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		int p = -1;
		for (int j = 0; j < n; j++)
		{
			int c;
			cin >> c;
			if (p != -1)
			{
				v[p].push_back(c);
				indegree[c]++;
			}
			p = c;
		}
	}
}

void print_vector()
{
	cout << "=================list===================\n";
	for (int i = 1; i <= N; i++)
	{
		cout << "N = " << i << " : ";
		for (auto iter = v[i].begin(); iter != v[i].end(); iter++)
			cout << *iter << " ";
		cout << "\n";
	}
}

void print_indegree()
{
	cout << "=================InDegree=================\n";
	for (int i = 1; i <= N; i++)
	{
		cout << "N = " << i << " : " << indegree[i] << "\n";
	}
}

void find_zero_indegree()
{
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	find_zero_indegree();
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (indegree[curr] > 0 || find(ans.begin(), ans.end(), curr) != ans.end())
			continue;
		ans.push_back(curr);
		for (auto iter = v[curr].begin(); iter != v[curr].end(); iter++)
		{
			indegree[*iter]--;
			if (indegree[*iter] == 0)
				q.push(*iter);
		}
	}

	if (ans.size() != N)
		cout << 0;
	else
		for (auto iter = ans.begin(); iter != ans.end(); iter++)
			cout << *iter << "\n";
}
