#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;

int board[100][100];

void Recursion(int x, int y, int size)
{
    int num = board[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] == num)
                continue;
            cout << "(";
            size /= 2;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    int nx = x + (i * size);
                    int ny = y + (j * size);
                    Recursion(nx, ny, size);
                }
            }
            cout << ")";
            return;
        }
    }
    cout << board[x][y];
}

int main()
{
    cin >> N;
    cin.tie(0);
    ios::sync_with_stdio(0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }
    }
    Recursion(0, 0, N);
}
