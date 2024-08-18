#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;

int A[201][201];
int C[201];

void input()
{
	for (int i = 0; i <= 200; i++)
		fill(A[i], A[i] + 200, 1000000000);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		A[u][v] = cost;
	}
	for (int i = 1; i <= N; i++)
		A[i][i] = 0;
	cin >> K;
	for (int i = 0; i < K; i++)
		cin >> C[i];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	input();

	for (int k = 1; k <= N; k++)
		for (int u = 1; u <= N; u++)
			for (int v = 1; v <= N; v++)
				A[u][v] = min(A[u][v], A[u][k] + A[k][v]);

	vector<int> ans;
	int _min = 1000000000;
	for (int i = 1; i <= N; i++)
	{
		int i_min = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i == j)
				continue;
			i_min = max(i_min, A[j][i] + A[i][j]);
		}
		if (i_min < _min)
		{
			ans.clear();
			ans.push_back(i);
			_min = i_min;
		}
		else if (i_min == _min)
		{
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());
	for (auto nxt : ans)
		cout << nxt << "\n";
}