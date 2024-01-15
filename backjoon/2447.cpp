#include <iostream>
#include <algorithm>
using namespace std;

int N;
int board[7000][7000];

void Recursion(int x, int y, int N, bool empty)
{
    if (N == 1)
    {
        if (empty)
            board[x][y] = 1;
        else
            board[x][y] = 0;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int nx = x + (i * N / 3);
            int ny = y + (j * N / 3);
            if (i == 1 && j == 1)
                Recursion(nx, ny, N / 3, 0);
            else
                Recursion(nx, ny, N / 3, empty);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    Recursion(0, 0, N, 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
}