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

vector<vector <int> > gBoard(9, vector<int>(9, 0));
vector<pair<int, int> >cctvs;
void dirFill(vector<vector <int> > &board, int dir, int x, int y)
{
    if (dir == LEFT)
    {
        for (int i = y - 1; i >= 0; i--)
        {
            if (board[x][i] == 6)
                return;
            if (board[x][i] != 0)
                continue;;
            board[x][i] = -1;
        }
    }
    else if (dir == RIGHT)
    {
        for (int i = y + 1; i < M; i++)
        {
            if (board[x][i] == 6)
                return;
            if (board[x][i] != 0)
                continue;
            board[x][i] = -1;
        }
    }
    else if (dir == UP)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (board[i][y] == 6)
                return;
            if (board[i][y] != 0)
                continue;
            board[i][y] = -1;
        }
    }
    else if (dir == DOWN)
    {
        for (int i = x + 1; i < N; i++)
        {
            if (board[i][y] == 6)
                return;
            if (board[i][y] != 0)
                continue;
            board[i][y] = -1;
        }
    }
}

void back(vector<vector<int> > board,int curr)
{
    if (curr == cctvs.size())
    {
        int _min = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j] == 0)
                    _min++;
        if (_min < ret)
            ret = _min;
        return ;
    }
    else if (board[cctvs[curr].X][cctvs[curr].Y] == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            vector<vector<int> > tmp(board);
            dirFill(tmp, i, cctvs[curr].X, cctvs[curr].Y);
            back(tmp, curr + 1);
        }
    }
    else if (board[cctvs[curr].X][cctvs[curr].Y] == 2)
    {
        for (int i = 0; i < 2; i++)
        {
            vector<vector<int> > tmp(board);
            dirFill(tmp, i, cctvs[curr].X, cctvs[curr].Y);
            dirFill(tmp, i + 2, cctvs[curr].X, cctvs[curr].Y);
            back(tmp, curr + 1);
        }
    }
    else if (board[cctvs[curr].X][cctvs[curr].Y] == 3)
    {
        for (int i = 0; i < 4; i++)
        {
            vector<vector<int> > tmp(board);
            dirFill(tmp, i, cctvs[curr].X, cctvs[curr].Y);
            dirFill(tmp, (i + 1) % 4, cctvs[curr].X, cctvs[curr].Y);
            back(tmp, curr + 1);
        }
    }
    else if (board[cctvs[curr].X][cctvs[curr].Y] == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            vector<vector<int> > tmp(board);
            dirFill(tmp, i, cctvs[curr].X, cctvs[curr].Y);
            dirFill(tmp, (i + 1) % 4, cctvs[curr].X, cctvs[curr].Y);
            dirFill(tmp, (i + 2) % 4, cctvs[curr].X, cctvs[curr].Y);
            back(tmp, curr + 1);
        }
    }
    else if (board[cctvs[curr].X][cctvs[curr].Y] == 5)
    {
        vector<vector<int> > tmp(board);
        dirFill(tmp, LEFT, cctvs[curr].X, cctvs[curr].Y);
        dirFill(tmp, UP, cctvs[curr].X, cctvs[curr].Y);
        dirFill(tmp, RIGHT, cctvs[curr].X, cctvs[curr].Y);
        dirFill(tmp, DOWN, cctvs[curr].X, cctvs[curr].Y);
        back(tmp, curr + 1);
    }
}


int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> gBoard[i][j];
            if (gBoard[i][j] != 0 && gBoard[i][j] != 6)
                cctvs.push_back(make_pair(i, j));
        }
    }
    back(gBoard, 0);
    cout << ret;
}