#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

int vis[101][101] = {-1};

int solution(vector<vector<int>> maps)
{
	int answer = -1;
	N = maps.size();
	M = maps[0].size();
	queue<pair<int, int>> q;
	q.push({0, 0});
	vis[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (vis[nx][ny] || maps[nx][ny] == 0)
				continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.push({nx, ny});
		}
	}

	if (vis[N - 1][M - 1])
		answer = vis[N - 1][M - 1];
	return answer;
}