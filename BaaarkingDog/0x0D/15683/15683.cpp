#include <iostream>
#include <vector>
#define X first
#define Y second

enum dir {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

using namespace std;
int N;
int M;
int ret = 100;
vector<pair<int, int> >cctvs;
int board[9][9];

void dirFill(int (&board)[9][9], int dir, int x, int y)
{
    if (dir == LEFT)
    {
        for (int i = y - 1; y >= 0; i--)
        {
            if (board[x][i] == 6)
                break;
            board[x][i] = -1;
        }
    }
    else if (dir == RIGHT)
    {
        for (int i = y + 1; y < M; i++)
        {
            if (board[x][i] == 6)
                break;
            board[x][i] = -1;
        }
    }
    else if (dir == UP)
    {
        for (int i = x - 1; x >= 0; i--)
        {
            if (board[i][y] == 6)
                break;
            board[i][y] = -1;
        }
    }
    else if (dir == DOWN)
    {
        for (int i = x + 1; x < N; i++)
        {
            if (board[i][y] == 6)
                break;
            board[i][y] = -1;
        }
    }
}


void back(int curr)
{
    if (curr == cctvs.size() - 1)
    {
        ret = 0;
        return ;
    }
    if (board[cctvs[curr].X][cctvs[curr].Y] == 1)
    {
        for (int i = 0; i < 4; i++)
        {
        }
    }
    // if (board[cctvs[curr].X][cctvs[curr].Y] == 2)
    // {
    // }
    // if (board[cctvs[curr].X][cctvs[curr].Y] == 3)
    // {
    // }
    // if (board[cctvs[curr].X][cctvs[curr].Y] == 4)
    // {
    // }
    // if (board[cctvs[curr].X][cctvs[curr].Y] == 5)
    // {
    // }
}


int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0 && board[i][j] != 6)
                cctvs.push_back(make_pair(i, j));
        }
    }
    back(0);
    cout << ret;
}