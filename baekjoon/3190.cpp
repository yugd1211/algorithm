#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
int N;
int K;
int L;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int second;
int dir;
int board[101][101];
bool apples[101][101];
priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
deque<pair<int, int>> dq;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		apples[x][y] = true;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int X;
		char C; // L = left, D = right
		cin >> X >> C;
		pq.push({X, C});
	}
	board[1][1] = 1;
	dq.push_back({1, 1});
	while (1)
	{
		if (pq.top().first == second)
		{
			if (pq.top().second == 'L')
			{
				dir--;
				if (dir == -1)
					dir = 3;
			}
			else
				dir++;
			pq.pop();
		}
		int nx = dq.front().first + dx[dir % 4];
		int ny = dq.front().second + dy[dir % 4];
		second++;
		if (nx <= 0 || ny <= 0 || nx > N || ny > N)
			break;
		if (board[nx][ny])
			break;
		dq.push_front({nx, ny});
		board[nx][ny] = true;
		if (apples[nx][ny])
			apples[nx][ny] = false;
		else
		{
			board[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
	}
	cout << second;
}