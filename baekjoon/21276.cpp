#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int N; // < 1000
int M; // < 500000
map<string, int> family_tree;
int depth[1001];
int indegree[1001];
vector<int> graph[1001];
vector<int> parent[1001];
vector<string> progenitor;
queue<int> q;

// 문제 풀이
// 위상정렬로 정렬하는 와중 indegree가 1이상인 경우는 해당 노드는 현재 노드 이외의 부모가 있다는 얘기이므로 해당 간선을 없애준다.

string find_name(int index)
{
	for (auto iter = family_tree.begin(); iter != family_tree.end(); iter++)
	{
		if (iter->second == index)
			return iter->first;
	}
	return NULL;
}

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		family_tree.insert({s, i});
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string a, b;
		cin >> a >> b;
		int c = family_tree.find(a)->second;
		int p = family_tree.find(b)->second;
		graph[p].push_back(c);
		parent[c].push_back(p);
		indegree[c]++;
	}
}

void find_zero_indegree()
{
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			q.push(i);
			progenitor.push_back(find_name(i));
		}
	}
}

void erase_grandparent()
{
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		int curr = 0;
		int en = graph[p].size();
		int cnt = 0;
		while (cnt < en)
		{
			if (indegree[graph[p][curr]] > 1)
			{
				indegree[graph[p][curr]]--;
				parent[graph[p][curr]].erase(find(parent[graph[p][curr]].begin(), parent[graph[p][curr]].end(), p));
				graph[p].erase(find(graph[p].begin(), graph[p].end(), graph[p][curr]));
			}
			else
			{
				q.push(graph[p][curr]);
				curr++;
			}
			cnt++;
		}
	}
}

void print_progenitor()
{
	cout << progenitor.size() << '\n';
	sort(progenitor.begin(), progenitor.end());
	for (int i = 0; i < progenitor.size(); i++)
		cout << progenitor[i] << ' ';
	cout << '\n';
}

void print_child()
{
	for (auto iter = family_tree.begin(); iter != family_tree.end(); iter++)
	{
		vector<string> vec;
		cout << iter->first << ' ' << graph[iter->second].size() << ' ';
		for (int i = 0; i < graph[iter->second].size(); i++)
			vec.push_back(find_name(graph[iter->second][i]));
		sort(vec.begin(), vec.end());
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << ' ';
		cout << '\n';
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	find_zero_indegree();
	erase_grandparent();
	print_progenitor();
	print_child();
}