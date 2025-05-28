#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 시간초과
// N : 10000
// M : 100000
// 시간 복잡도 : O(N^2 * M) = O(1000000000000) => 시간 초과

int N, M;
vector<pair<int, int>> point;

int GetDistance(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int answer = 2000000000;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		point.push_back({u, v});
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			int dis = 0;
			for (int k = 0; k < point.size(); k++)
				dis += GetDistance(point[k], {i, j});
			answer = min(dis, answer);
		}
	}
	cout << answer;
}