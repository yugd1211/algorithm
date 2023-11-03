#include <iostream>
#include <vector>

using namespace std;

enum movement
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};

vector<vector <int> > board;
int boardSize;
int gMax = 0;

void backTracking(int dir, vector<vector <int> > bd, int cnt)
{

    // 현재는 합치고 다음 칸을 0으로 바꾸는 방식으로 했는데
    // 처음 생각한건 합치고 다음칸을 erase로 지우고 맨뒤에 0을 생성하는걸 생각했다.
    // 이렇게하면 20개에 대한 모든 노드를 땡겨오는 연산을 안해도되니까?
    // 어떤게 더 좋은 방식인지는 모르겠다.
    if (dir == LEFT)
    {
        for (int hight = 0; hight < boardSize; hight++)
        {
            for (int width = 0; width < boardSize - 1; width++)
            {
                if (bd[hight][width] != 0 && bd[hight][width] == bd[hight][width + 1])
                {
                    bd[hight][width] *= 2;
                    bd[hight][width + 1] = 0;
                }
                else if (bd[hight][width] == 0)
                {
                    for (int i = width; i < boardSize - 1; i++)
                    {
                        bd[hight][i] = bd[hight][i + 1];
                    }
                    bd[hight][boardSize - 1] = 0;
                }
            }
        }
    }
    else if (dir == RIGHT)
    {
        for (int hight = 0; hight < boardSize; hight++)
        {
            for (int width = boardSize - 1; width > 0; width--)
            {
                if (bd[hight][width] != 0 && bd[hight][width] == bd[hight][width -1])
                {
                    bd[hight][width] *= 2;
                    bd[hight][width - 1] = 0;
                }
                else if (bd[hight][width] == 0)
                {
                    for (int i = width; i > 0; i--)
                    {
                        bd[hight][i] = bd[hight][i - 1];
                    }
                    bd[hight][0] = 0;
                }
            }
        }
    }
    else if (dir == UP)
    {
        for (int width = 0; width < boardSize; width++)
        {   
            for (int hight = 0; hight < boardSize - 1; hight++)
            {
                if (bd[hight][width] != 0 && bd[hight][width] == bd[hight + 1][width])
                {
                    bd[hight][width] *= 2;
                    bd[hight + 1][width] = 0;
                }
                else if (bd[hight][width] == 0)
                {
                    for (int i = hight; i < boardSize - 1; i++)
                        bd[i][width] = bd[i + 1][width];
                    bd[hight][boardSize - 1] = 0;
                }
            }
        }
    }
    else if (dir == DOWN)
    {
        for (int width = 0; width < boardSize; width++)
        {   
            for (int hight = boardSize - 1; hight > 0; hight--)
            {
                if (bd[hight][width] != 0 && bd[hight][width] == bd[hight - 1][width])
                {
                    bd[hight][width] *= 2;
                    bd[hight - 1][width] = 0;
                }
                else if (bd[hight][width] == 0)
                {
                    for (int i = hight; i > 0; i--)
                        bd[i][width] = bd[i - 1][width];
                    bd[0][width] = 0;
                }
            }
        }
    }
    if (cnt == 4)
    {
        for (int i = 0; i < boardSize; i++)
            for (int j = 0; j < boardSize; j++)
                if (gMax < bd[i][j])
                    gMax = bd[i][j];
        return ;
    }
    for (int i = 0; i < 4; i++)
        backTracking(i, bd, cnt + 1);
}


int main()
{
    cin >> boardSize;
    board.assign(boardSize, vector<int>(boardSize, 0));
    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < boardSize; j++)
            cin >> board[i][j];
    for (int i = 0; i < 4; i++)
        backTracking(i, board, 0);
    cout << "ret = " << gMax;   
    return 0;
}