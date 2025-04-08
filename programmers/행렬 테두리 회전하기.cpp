#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int adj[101][101];

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;

	for (int i = 1; i <= rows; i++)
		for (int j = 1; j <= columns; j++)
			adj[i][j] = (i - 1) * columns + j;

	for (auto iter : queries)
	{
		vector<int> curr = iter;
		int x1 = curr[0];
		int y1 = curr[1];
		int x2 = curr[2];
		int y2 = curr[3];

		int prev = adj[x1][y1];
		int m = prev;

		for (int i = y1 + 1; i <= y2; i++)
		{
			swap(adj[x1][i], prev);
			m = min(m, prev);
		}
		for (int i = x1 + 1; i <= x2; i++)
		{
			swap(adj[i][y2], prev);
			m = min(m, prev);
		}
		for (int i = y2 - 1; i >= y1; i--)
		{
			swap(adj[x2][i], prev);
			m = min(m, prev);
		}
		for (int i = x2 - 1; i >= x1; i--)
		{
			swap(adj[i][y1], prev);
			m = min(m, prev);
		}
		answer.push_back(m);
	}
	return answer;
}