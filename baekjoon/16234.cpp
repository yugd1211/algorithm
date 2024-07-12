#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 50

// 현재 풀고있는 방식으로는 안풀릴거같다.
// 다음에 다시..

int N; // < 50
int A[MAX + 1][MAX + 1];
int vis[MAX + 1][MAX + 1];
int L, R;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> vec;

void input()
{
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
}

void clear_vis()
{
	for (int i = 0; i < MAX; i++)
	{
		fill(vis[i], vis[i] + MAX + 1, 0);
	}
}

void dfs(int x, int y)
{
	if (vis[x][y])
		return;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx > N || ny > N)
			continue;
		if (vis[nx][ny])
			continue;
		int diff = abs(A[x][y] - A[nx][ny]);
		if (diff < L || diff > R)
			continue;
		vec.push_back({nx, ny});
		vis[nx][ny] = vis[x][y] + 1;
		dfs(nx, ny);
	}
}

int average_country()
{
	int total = 0;
	int ret = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int x = vec[i].first;
		int y = vec[i].second;
		total += A[x][y];
	}
	int average = total / vec.size();
	for (int i = 0; i < vec.size(); i++)
	{
		int x = vec[i].first;
		int y = vec[i].second;
		A[x][y] = average;
		ret = max(vis[x][y], ret);
	}
	return ret;
}

bool open_line()
{
	int merge_cnt = 0;
	clear_vis();
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (vis[i][j])
				continue;
			vis[i][j] = 1;
			dfs(i, j);
			merge_cnt = max(merge_cnt, average_country());
			vec = vector<pair<int, int>>();
		}
	}
	if (merge_cnt > 1)
		return true;
	return false;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	while (open_line)
	{
	}
}
