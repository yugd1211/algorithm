#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;
#define MAX_INDEX 20
#define MAX_MOVE 100000000

// 문제풀이
// bfs를 재귀적으로 호출, 그러던중 상어가 먹을 수 있는 물고기를 만나면 queue를 초기화 후 해당 위치부터 다시 bfs 시작하는 방식이다.
// 여기서 문제는 같은 deep일 때 우선순위가 있다는것, 안될걸 알았지만 시도한 방법은 bfs의 방향호출을 우선순위에 맞게 상, 좌, 우, 하 순으로 호출하는것 당연하게도 실패
// 다음은 우선순위 큐를 사용하는것
// deep count가 제일작은순으로, x, y가 작은순으로 정렬하면 같은 deep일때 가장 위의 것 그중에서도 가장왼쪽의 노드를 먼저 호출 할 것이라 예측했지만 무슨 이유인지 실패했다.
// 예시가 너무 괴랄해서 순수 출력문으로 디버깅하기 힘들어서 일단 다른 방식으로 풀어보려고한다.
// 생각해둔 방법은 무식하게 하는방식이다.
// N이 작기 때문에 그냥 완전탐색으로 하려고한다.
// bfs, dfs 뭐가 됐듯 재귀함수를 통해 현재 상어가 갈수 있는, 먹을 수 있는 모든 곳을 방문하며 visited에 이동횟수를 저장한다.
// 상어가 먹을 수 있는 물고기를 만나면 어떤 방식으로든 흔적을 남긴다(이동 횟수와 함께).
// 탐색이 끝나면 상어가 먹을 수 있는 물고기들을 비교하며 제일 이동횟수가 적게 먹을 수 있는 물고기들을 추린다.
// 이동횟수가 최저인 물고기가 다수일경우 해당 이동횟수를 맨위 맨왼쪽부터 비교하며 먹을 수 있는 물고기를 찾으면 된다.
// 이렇게 적다보니 pq의 방식의 오류를 찾았다. 저 방식은 상어를 기준으로 제일 위, 제일 왼쪽이다 (상대 좌표).
// 여기서 말하는 제일위, 제일 왼쪽의 물고기는 절대좌표를 기준으로 하기때문에 틀렸을것으로 예측함

int N; // 2 <= N <= 20
int A[21][21];
int vis[21][21];
int ans = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
queue<pair<int, int>> q;

void clear_vis()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == 9)
			{
				A[i][j] = 0;
				q.push({i, j});
			}
		}
	}
}

void bfs(int curr_size)
{
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (vis[nx][ny])
				continue;
			if (A[nx][ny] > curr_size)
				continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

int find_min_move(int curr_size)
{
	int ret = MAX_MOVE;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!vis[i][j] || !A[i][j])
				continue;
			if (curr_size > A[i][j])
				ret = min(ret, vis[i][j]);
		}
	}
	return ret;
}

pair<int, int> find_min_pos(int min_move, int curr_size)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == min_move && A[i][j] && A[i][j] < curr_size)
				return {i, j};
		}
	}
	return {0, 0};
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	int x, y;
	int curr_size = 2;
	int eat_size = 0;
	int ans = 0;
	while (1)
	{
		clear_vis();
		bfs(curr_size);
		int min_move = find_min_move(curr_size);
		if (min_move == MAX_MOVE)
			break;
		tie(x, y) = find_min_pos(min_move, curr_size);
		ans += vis[x][y];
		eat_size++;
		A[x][y] = 0;
		q.push({x, y});
		if (curr_size == eat_size)
		{
			curr_size++;
			eat_size = 0;
		}
	}
	cout << ans;
}
