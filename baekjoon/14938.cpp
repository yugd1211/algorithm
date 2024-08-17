#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제풀이
// 플로이드 알고리즘으로 최적해를 찾은뒤 모든 정점을기준으로 거리내로 갈 수있는 곳을 체크했다.

int N;
int M;
int R;

int item[101];
int A[101][101];

void input()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		cin >> item[i];
	for (int i = 0; i <= N; i++)
		fill(A[i], A[i] + 1 + N, 1000000000);
	while (R--)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		A[u][v] = cost;
		A[v][u] = cost;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();

	for (int k = 1; k <= N; k++)
		for (int u = 1; u <= N; u++)
			for (int v = 1; v <= N; v++)
				A[u][v] = min(A[u][v], A[u][k] + A[k][v]);

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		int cnt = item[i];
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			if (A[i][j] > M || A[i][j] == 1000000000)
				continue;
			cnt += item[j];
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}