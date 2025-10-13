#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int board[9][9];
bool found = false;

bool CheckPutInNumber(int x, int y, int num)
{
	// horizontal
	for (int i = 0; i < 9; i++)
	{
		if (board[y][i] == num)
			return false;
	}

	// vertical
	for (int i = 0; i < 9; i++)
	{
		if (board[i][x] == num)
			return false;
	}

	// layer
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[y / 3 * 3 + i][x / 3 * 3 + j] == num)
				return false;
		}
	}
	return true;
}

void bt(int index)
{
	if (found)
		return;

	if (index == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << "\n";
		}
		found = true;
		return;
	}

	int x = index % 9;
	int y = index / 9;

	if (board[y][x] == 0)
	{
		for (int num = 1; num <= 9; num++)
		{
			if (found)
				return;
			if (CheckPutInNumber(x, y, num))
			{
				board[y][x] = num;
				bt(index + 1);
				board[y][x] = 0;
			}
		}
	}
	else
	{
		bt(index + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}
	bt(0);
}