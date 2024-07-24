#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, M, K;
int A[11][11];
int board[11][11];
vector<int> tree[11][11];
queue<int> dead_tree[11][11];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void sort_tree()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			sort(tree[i][j].begin(), tree[i][j].end());
}

void input()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
			board[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}
	sort_tree();
}

void spring()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			auto iter = tree[i][j].begin();
			auto slice_iter = tree[i][j].end();
			while (iter != tree[i][j].end())
			{
				if (board[i][j] >= *iter)
				{
					board[i][j] -= (*iter);
					*iter = *iter + 1;
				}
				else
				{
					if (slice_iter > iter)
						slice_iter = iter;
					dead_tree[i][j].push(*iter);
				}
				iter++;
			}
			tree[i][j].erase(slice_iter, tree[i][j].end());
		}
	}
}

void summer()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			while (!dead_tree[i][j].empty())
			{
				board[i][j] += dead_tree[i][j].front() / 2;
				dead_tree[i][j].pop();
			}
		}
	}
}

void autumn()
{
	for (int x = 1; x <= N; x++)
	{
		for (int y = 1; y <= N; y++)
		{
			for (auto iter = tree[x][y].begin(); iter != tree[x][y].end(); iter++)
			{
				if (*iter % 5)
					continue;
				for (int i = 0; i < 8; i++)
				{
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 1 || ny < 1 || nx > N || ny > N)
						continue;
					tree[nx][ny].push_back(1);
				}
			}
		}
	}
}

void winter()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			board[i][j] += A[i][j];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	input();
	for (int i = 0; i < K; i++)
	{
		spring();
		sort_tree();
		summer();
		autumn();
		sort_tree();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ans += tree[i][j].size();
	cout << ans;
}