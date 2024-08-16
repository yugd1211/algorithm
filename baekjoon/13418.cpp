#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int p[1001];
long long ans;

// cost, dest
vector<tuple<int, int, int>> graph;

int GetParent(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = GetParent(p[x]);
}

void UnionParent(int a, int b)
{
	a = GetParent(a);
	b = GetParent(b);
	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}

bool CompareParent(int a, int b)
{
	if (GetParent(a) == GetParent(b))
		return 1;
	return 0;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i <= M; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		graph.push_back({cost, u, v});
	}
}

void print_parent()
{
	cout << "============parent===========\n";
	for (int i = 0; i <= N; i++)
	{
		cout << p[i] << "\n";
	}
}

int Find_Path(bool isMin)
{
	for (int i = 0; i <= 1000; i++)
		p[i] = i;
	int ret = 0;
	if (isMin)
		sort(graph.begin(), graph.end(), greater<>());
	else
		sort(graph.begin(), graph.end());
	for (int i = 0; i < graph.size(); i++)
	{
		int u, v, cost;
		tie(cost, u, v) = graph[i];
		if (CompareParent(u, v))
			continue;
		UnionParent(u, v);
		if (cost)
			continue;
		ret++;
	}
	return ret;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	long long _min = 0;
	long long _max = 0;
	_min = Find_Path(true);
	_max = Find_Path(false);
	_min *= _min;
	_max *= _max;
	cout << _max - _min;
}