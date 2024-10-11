#include <string>
#include <vector>
#include <iostream>

using namespace std;

int firstSize, secondSize;

int CheckWin(vector<string> &board, char player)
{
	for (int i = 0; i < 3; i++)
		if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
			(board[0][i] == player && board[1][i] == player && board[2][i] == player))
			return 1;
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
		(board[2][0] == player && board[1][1] == player && board[0][2] == player))
		return 1;
	return 0;
}

int solution(vector<string> board)
{
	int answer = 1;
	for (auto &row : board)
		for (char cell : row)
		{
			if (cell == 'O')
				firstSize++;
			else if (cell == 'X')
				secondSize++;
		}
	if (firstSize < secondSize || firstSize > secondSize + 1)
		return 0;
	if (CheckWin(board, 'O') && firstSize == secondSize)
		return 0;
	if (CheckWin(board, 'X') && firstSize != secondSize)
		return 0;
	return answer;
}