#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 크게 바꾼 것은 없이 N^3을 N^2 + N으로 바꿔주었다.
// dfs에서 순회 하는것만해도 N만큼 순회를 하는 방식에서 자료구조를 배열에서 vector로 변경하면서 간선이 연결되어 있는 곳만 순회하는 방식으로 변경
// 간선의 갯수는 N - 1임으로 dfs에서 순회하는 시간복잡도가 N^2에서 N으로 확줄어든다.
// 결과는 통과

vector<pair<int, int>> vec[5001];

bool vis[5001];

int N;
int Q;

void clear_vis()
{
	fill(vis, vis + 5001, 0);
}

int dfs(int k, int v)
{
	int res = 0;
	for (int i = 0; i < vec[v].size(); i++)
	{
		if (vis[vec[v][i].first])
			continue;
		if (vec[v][i].second < k)
			continue;
		res++;
		vis[vec[v][i].first] = 1;
		res += dfs(k, vec[v][i].first);
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
		vec[p].push_back({q, r});
		vec[q].push_back({p, r});
	}

	for (int i = 0; i < Q; i++)
	{
		int k, v;
		cin >> k >> v;
		vis[v] = 1;
		cout << dfs(k, v) << "\n";
		clear_vis();
	}
}