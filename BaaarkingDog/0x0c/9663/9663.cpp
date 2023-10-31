#include <iostream>

using namespace std;
int N;
int cnt;
bool board[15][15];

bool checkQueen(int x, int y)
{
    for (int i = 0; i < x; i++)
    {
        if (board[i][y])
            return false;
        // 0 이하 N 이상을 확실하게 체크
        if (y - x + i >= 0 && board[i][y - x + i])
            return false;
        if (y + x - i < N && board[i][y + x - i])
            return false;
    }
    return 1;
}

void func(int curr)
{
    if (curr == N)
    {
        cnt++;
        return ;
    }
    for (int i = 0; i < N; i++)
    {
        if (checkQueen(curr, i))
        {
            board[curr][i] = 1;
            func(curr + 1);
            board[curr][i] = 0;
        }
    }
}

int main()
{
    cin >> N;
    func(0);
    cout << cnt;
    return 0;
}