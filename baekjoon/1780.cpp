#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int board[7000][7000];
int cnt[3];

void Recursion(int x, int y, int n)
{
    int num = board[x][y];
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (board[i][j] == num)
                continue;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    Recursion(x + (i * n / 3), y + (j * n / 3), n / 3);
            return;
        }
    }
    if (board[x][y] == -1)
        cnt[0]++;
    else if (board[x][y] == 0)
        cnt[1]++;
    else
        cnt[2]++;
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
    cout << cnt[2] << "\n";
}
