#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int M;
long long A[101][101];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < 101; i++)
		fill(A[i], A[i] + 1 + N, 1000000001);
	while (M--)
	{
		int u, v;
		long long cost;
		cin >> u >> v >> cost;
		A[u][v] = min(A[u][v], cost);
	}

	for (int k = 1; k <= N; k++)
	{
		for (int u = 1; u <= N; u++)
		{
			for (int v = 1; v <= N; v++)
			{
				A[u][v] = min(A[u][v], A[u][k] + A[k][v]);
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j || A[i][j] == 1000000001)
				cout << '0';
			else
				cout << A[i][j];
			cout << ' ';
		}
		cout << '\n';
	}
}