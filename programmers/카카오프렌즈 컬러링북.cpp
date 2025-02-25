#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int M, N;
int vis[101][101];
vector<vector<int>> board;
int area[10001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int cnt, int curr)
{
	if (vis[x][y] || board[x][y] != curr)
		return;
	vis[x][y] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= M || ny >= N)
			continue;
		dfs(nx, ny, cnt, curr);
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);

	board = picture;
	N = n;
	M = m;
	int cnt = 0;
	for (int i = 0; i < 101; i++)
		fill(vis[i], vis[i] + 101, 0);
	fill(area, area + 10001, 0);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j] || board[i][j] == 0)
				continue;
			dfs(i, j, ++number_of_area, board[i][j]);
		}
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			area[vis[i][j]]++;

	for (int i = 1; i < 10001; i++)
		max_size_of_one_area = max(max_size_of_one_area, area[i]);

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}