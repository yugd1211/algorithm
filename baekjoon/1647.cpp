#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> adj[100001];
priority_queue<
	tuple<int, int, int>,
	vector<tuple<int, int, int>>,
	greater<tuple<int, int, int>>>
	pq;

int N, M;
int p[100001];

int getParent(int a)
{
	if (p[a] == a)
		return a;
	return p[a] = getParent(p[a]);
}

void union_find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return;
	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}

bool same_parent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	else
		return false;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		p[i] = i;
	while (M--)
	{
		int u, v, c;
		cin >> u >> v >> c;
		pq.push({c, u, v});
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	int maxCost = 0;
	int res = 0;

	while (!pq.empty())
	{
		int u, v, c;
		tie(c, u, v) = pq.top();
		pq.pop();
		if (!same_parent(u, v))
		{
			res += c;
			maxCost = max(maxCost, c);
			union_find(u, v);
		}
	}
	cout << res - maxCost;
}