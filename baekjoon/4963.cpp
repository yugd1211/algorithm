#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int A[51][51];
int vis[51][51];
queue<pair<int, int>> q;

void clear_array()
{
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			A[i][j] = 0;
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			vis[i][j] = 0;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	while (1)
	{
		int w, h;
		int cnt = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		clear_array();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> A[i][j];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!A[i][j] || vis[i][j])
					continue;
				q.push({i, j});
				cnt++;
				while (!q.empty())
				{
					int x, y;
					tie(x, y) = q.front();
					q.pop();
					if (vis[x][y])
						continue;
					vis[x][y] = cnt;
					for (int i = 0; i < 8; i++)
					{
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (nx < 0 || ny < 0 || nx >= h || ny >= w)
							continue;
						if (vis[nx][ny] || !A[nx][ny])
							continue;
						q.push({nx, ny});
					}
				}
			}
		}
		cout << cnt << "\n";
	}
}