#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
void pick_1();
void pick_2(int x, int y, std::vector<std::vector<int>> vec);
void pick_3(int x, int y, std::vector<std::vector<int>> vec);
void print_board(std::vector<std::vector<int>> vec);
using namespace std;

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int N, M;
int ret = 0;

// 0 = 빈칸, 1 = 벽, 2 = 바이러스
std::vector<std::vector<int>> board(9, std::vector<int>(9));
queue<pair<int, int>> q;
queue<pair<int, int>> tmp;

void print_board(std::vector<std::vector<int>> vec)
{
	cout << "===============board===============\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << vec[i][j] << " ";
		cout << "\n";
	}
}

void pick_1()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
			{
				std::vector<std::vector<int>> vec = board;
				vec[i][j] = 1;
				pick_2(i, j, vec);
			}
		}
	}
}

void pick_2(int x, int y, std::vector<std::vector<int>> vec)
{
	for (int i = x; i < N; i++)
	{
		for (int j = i == x ? y : 0; j < M; j++)
		{
			if (vec[i][j] == 0)
			{
				std::vector<std::vector<int>> tmp = vec;
				tmp[i][j] = 1;

				pick_3(i, j, tmp);
			}
		}
	}
}

void pick_3(int x, int y, std::vector<std::vector<int>> vec)
{
	for (int i = x; i < N; i++)
	{
		for (int j = i == x ? y : 0; j < M; j++)
		{
			if (vec[i][j] == 0)
			{
				std::vector<std::vector<int>> vec1 = vec;
				vec1[i][j] = 1;
				tmp = q;
				while (!tmp.empty())
				{
					int x, y;
					tie(x, y) = tmp.front();
					tmp.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = x + dirX[i];
						int ny = y + dirY[i];
						if (nx < 0 || ny < 0 || nx >= N || ny >= M)
							continue;
						if (vec1[nx][ny] == 0)
						{
							vec1[nx][ny] = 2;
							tmp.push({nx, ny});
						}
					}
				}
				int cnt = 0;
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < M; j++)
					{
						if (vec1[i][j] == 0)
							cnt++;
					}
				}
				ret = max(cnt, ret);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				q.push({i, j});
		}
	}
	pick_1();
	cout << ret;
}