#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 이분탐색으로 풀었지만 풀이방법까지 혼자 도달하지는 못했다.
// 값을 나눈것을 cnt로 축적해나간다는 발상이 부족했다.
// 자꾸 해당 값으로 나눈걸 노드로 재귀적으로 호출해야된다는 생각에 갇혀있었다.

int N, M;
vector<int> adj;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		adj.push_back(n);
	}
	sort(adj.begin(), adj.end());
	int l = 0;
	int r = *(--adj.end());
	int ans = 0;
	while (l < r)
	{
		int mid = (l + r) / 2;
		int cnt = 0;

		if ((l + r) % 2)
			mid++;
		for (int i = 0; i < adj.size(); i++)
			cnt += adj[i] / mid;
		if (cnt >= N)
		{
			l = mid;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans;
}
