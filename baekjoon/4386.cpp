#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N;
vector<pair<long double, long double>> vec;
priority_queue<pair<long double, int>,
			   vector<pair<long double, int>>,
			   greater<pair<long double, int>>>
	pq;

long double edge[101][101];
bool vis[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		long double a, b;
		cin >> a >> b;
		vec.push_back({a, b});
	}

	for (int i = 0; i < N; i++)
	{
		long double cx = vec[i].first;
		long double cy = vec[i].second;
		for (int j = i + 1; j < N; j++)
		{
			long double nx = vec[j].first;
			long double ny = vec[j].second;

			long double d = sqrt(pow(nx - cx, 2) + pow(ny - cy, 2));
			edge[i][j] = edge[j][i] = d;
		}
	}

	vis[0] = true;
	for (int i = 1; i < N; i++)
	{
		pq.push({edge[0][i], i});
	}

	long double res = 0;
	while (!pq.empty())
	{
		auto [cost, dest] = pq.top();
		pq.pop();
		if (vis[dest])
			continue;
		vis[dest] = true;
		res += cost;
		for (int i = 0; i < N; i++)
		{
			if (!vis[i])
				pq.push({edge[dest][i], i});
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << res;
}
