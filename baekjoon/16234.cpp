#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
#define MAX 50

// 문제 풀이
// 일단 재귀를 통한 탐색이 필요하다.
// 현재 노드를 기준으로 상하좌우의 값들과 비교하며 재귀적으로 탐색을 이어나간다. DFS를 사용했지만 BFS여도 상관없다.
// 재귀의 종료 조건은 현재 노드와 상하좌우의 값을 비교하고, 값의 차이가 L, R의 사이값이 아니면 종료된다.
// 재귀 간에 탐색을 진행한 곳은 visited 배열에 체크하여 재탐색하지 않도록 막고, 모든 노드에 대해 DFS를 진행한다.
// 한 차례의 DFS가 끝나면 DFS를 진행하면서 재귀적으로 재탐색이 이루어진 곳들은 deque에 넣어 어느 노드들을 연합시킬지 리스트화한다.
// 해당 deque의 모든 노드들의 값의 평균을 구하고, 해당 deque에서 값을 빼내어 해당 노드의 값들을 평균값으로 대체한다.
// deque의 크기가 1 이상이면 이전과 다른 연합이 생겼다는 의미이므로 이때는 다시 모든 노드에 대해 DFS 탐색을 진행한다. 만약 모든 탐색이 끝날 때까지 이전과 다르지 않다면 종료한다.

int N; // < 50
int A[MAX + 1][MAX + 1];
int vis[MAX + 1][MAX + 1];
int L, R;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int>> dq;

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
		for (int j = 0; j < MAX; j++)
			vis[i][j] = 0;
}

void dfs(int x, int y)
{
	if (vis[x][y])
		return;
	vis[x][y] = 1;
	dq.push_back({x, y});
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N)
			continue;
		if (vis[nx][ny])
			continue;
		int diff = abs(A[x][y] - A[nx][ny]);
		if (diff < L || diff > R)
			continue;
		dfs(nx, ny);
	}
}

int average_country()
{
	int total = 0;
	int ret = 0;
	for (int i = 0; i < dq.size(); i++)
	{
		int x = dq[i].first;
		int y = dq[i].second;
		total += A[x][y];
	}
	int average = total / dq.size();
	ret = dq.size();
	while (!dq.empty())
	{
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();
		A[x][y] = average;
	}
	return ret;
}

bool open_line()
{
	int merge_cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j])
				continue;
			dfs(i, j);
			merge_cnt = max(merge_cnt, average_country());
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
	int ans = 0;
	while (open_line())
	{
		clear_vis();
		ans++;
	}
	cout << ans;
}
