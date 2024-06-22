#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[12];
vector<int> oper(4);

int g_max = -2000000000;
int g_min = 2000000000;

void dfs(int depth, int val, vector<int> oper_cnt)
{
	if (depth == N - 1)
	{
		g_max = max(g_max, val);
		g_min = min(g_min, val);
		return;
	}
	depth++;
	for (int i = 0; i < 4; i++)
	{
		if (oper_cnt[i] == 0)
			continue;
		auto tmp_oper = oper_cnt;
		int tmp_val = val;
		if (i == 0)
			tmp_val += A[depth];
		else if (i == 1)
			tmp_val -= A[depth];
		else if (i == 2)
			tmp_val *= A[depth];
		else if (i == 3)
			tmp_val /= A[depth];
		tmp_oper[i]--;
		dfs(depth, tmp_val, tmp_oper);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < 4; i++)
		cin >> oper[i];
	dfs(0, A[0], oper);
	cout << g_max << "\n";
	cout << g_min << "\n";
}