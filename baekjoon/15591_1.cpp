#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 타임에러

int arr[5001][5001];
int vis[5001];

int N;
int Q;

void clear_vis()
{
	fill(vis, vis + 5001, 0);
}

int dfs(int k, int v)
{
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		if (vis[i])
			continue;
		if (!arr[v][i] || arr[v][i] < k)
			continue;
		res++;
		vis[i] = 1;
		res += dfs(k, i);
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int p, q, r;
		cin >> p >> q >> r;
		arr[p][q] = r;
		arr[q][p] = r;
	}

	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;
		cout << dfs(k, v) << "\n";
		clear_vis();
	}
}