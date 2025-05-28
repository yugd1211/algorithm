#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 맨해튼 거리로 거리의 중앙값을 구해서 해당 중앙거리를 기준으로 모든 정점에서의 거리값을 구하는 방식으로 변경
// 시간복잡도 O(M)

int N, M;
int GetDistance(pair<int, int> p1, pair<int, int> p2) { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	vector<int> x(M), y(M);

	for (int i = 0; i < M; i++)
		cin >> x[i] >> y[i];

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	int mx = x[M / 2];
	int my = y[M / 2];

	int dis = 0;
	for (int k = 0; k < M; k++)
		dis += GetDistance({x[k], y[k]}, {mx, my});
	cout << dis;
}