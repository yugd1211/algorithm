#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int A[101][101];
int main()
{

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char k;
			cin >> k;
			if (k == '.')
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}

	int cnt_row = 0;
	int row = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] == 1)
				cnt_row++;
			else
				cnt_row = 0;

			if (cnt_row == 2)
				row++;
		}

		cnt_row = 0;
	}

	int col = 0;
	int cnt_col = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[j][i] == 1)
				cnt_col++;
			else
				cnt_col = 0;

			if (cnt_col == 2)
				col++;
		}

		cnt_col = 0;
	}

	cout << row << " " << col;

	return 0;
}