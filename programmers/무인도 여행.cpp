#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// X = 바다, 1 ~ 9 = 식량
int N, M;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[101][101];
int cnt[101][101];
int arr[10005];

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (vis[nx][ny])
			continue;
		if (cnt[nx][ny] == 0)
			continue;

		vis[nx][ny] = vis[x][y];
		dfs(nx, ny);
	}
}

vector<int> solution(vector<string> maps)
{
	vector<int> answer;
	N = maps.size();
	M = maps[0].size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maps[i][j] == 'X')
				continue;
			cnt[i][j] = maps[i][j] - '0';
		}
	}
	int visCnt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j])
				continue;
			if (maps[i][j] == 'X')
				continue;
			vis[i][j] = visCnt++;
			dfs(i, j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (vis[i][j] == 0)
				continue;
			arr[vis[i][j]] += cnt[i][j];
		}
	}
	for (int i = 1; i < visCnt; i++)
	{
		answer.push_back(arr[i]);
	}
	sort(answer.begin(), answer.end());
	if (answer.empty())
		answer.push_back(-1);
	return answer;
}