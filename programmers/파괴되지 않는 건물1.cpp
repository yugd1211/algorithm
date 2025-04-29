#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void applySKill(vector<vector<int>> &board, int type, int r1, int c1, int r2, int c2, int degree)
{
	for (int x = r1; x <= r2; x++)
		for (int y = c1; y <= c2; y++)
			board[x][y] += type == 1 ? degree * -1 : degree;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
	int answer = 0;
	for (auto iter : skill)
	{
		int type = iter[0];
		int r1 = iter[1];
		int c1 = iter[2];
		int r2 = iter[3];
		int c2 = iter[4];
		int degree = iter[5];
		for (int x = r1; x <= r2; x++)
			for (int y = c1; y <= c2; y++)
				board[x][y] += type == 1 ? degree * -1 : degree;
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] > 0)
				answer++;
	}

	return answer;
}