#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int board[129][129];

int N;
int cnt[2];

void Recursion(int x, int y, int size)
{
    int num = board[x][y];
    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (board[i][j] == num)
                continue;
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
            return;
        }
    }
    if (!board[x][y])
        cnt[0]++;
    else
        cnt[1]++;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    Recursion(0, 0, N);
    cout << cnt[0] << "\n";
    cout << cnt[1] << "\n";
}