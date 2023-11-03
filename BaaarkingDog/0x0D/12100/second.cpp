#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 문제를 다풀었는데 테스트케이스는 얼추 다 맞았는데 통과하지 못해서 몇시간을 헤매다 발견
// DOWN 을 실행하는 부분에서 queue에 값을 푸시할때 반대로 체크....

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
    if (dir == LEFT)
    {
        for (int hight = 0; hight < boardSize; hight++)
        {
            bool arr[21] = {};
            queue<int> stk;
            for (int width = 0; width < boardSize; width++)
                if (bd[hight][width] != 0)
                    stk.push(bd[hight][width]);
            std::fill(bd[hight].begin(), bd[hight].end(), 0);
            int i = 0;
            while (1)
            {
                if (stk.empty())
                    break;
                int num = stk.front();
                stk.pop();
                if (i != 0 && bd[hight][i - 1] == num && arr[i - 1] == false)
                {
                    bd[hight][i - 1] *= 2;
                    arr[i - 1] = 1;
                }
                else
                    bd[hight][i++] = num;
            }
        }
    }
    if (dir == RIGHT)
    {
        for (int hight = 0; hight < boardSize; hight++)
        {
            bool arr[21] = {};
            queue<int> stk;
            for (int width = boardSize - 1; width >= 0; width--)
                if (bd[hight][width] != 0)
                    stk.push(bd[hight][width]);
            std::fill(bd[hight].begin(), bd[hight].end(), 0);
            int i = boardSize - 1;
            while (1)
            {
                if (stk.empty())
                    break;
                int num = stk.front();
                stk.pop();
                if (i != boardSize - 1 && bd[hight][i + 1] == num && arr[i + 1] == false)
                {
                    bd[hight][i + 1] *= 2;
                    arr[i + 1] = 1;
                }
                else
                    bd[hight][i--] = num;
            }
        }
    }
    if (dir == UP)
    {
        for (int width = 0; width < boardSize; width++)
        {
            bool arr[21] = {};
            queue<int> stk;
            for (int hight = 0; hight < boardSize; hight++)
                if (bd[hight][width] != 0)
                    stk.push(bd[hight][width]);
            for (int i = 0; i < boardSize; i++)
                bd[i][width] = 0;
            int i = 0;
            while (1)
            {
                if (stk.empty())
                    break;
                int num = stk.front();
                stk.pop();
                if (i != 0 && bd[i - 1][width] == num && arr[i - 1] == false)
                {
                    bd[i - 1][width] *= 2;
                    arr[i - 1] = 1;
                }
                else
                    bd[i++][width] = num;
            }
        }
    }
    if (dir == DOWN)
    {
        for (int width = 0; width < boardSize; width++)
        {
            bool arr[21] = {};
            queue<int> stk;
            for (int hight = boardSize - 1; hight >= 0; hight--)
                if (bd[hight][width] != 0)
                    stk.push(bd[hight][width]);
            for (int i = 0; i < boardSize; i++)
                bd[i][width] = 0;
            int i = boardSize - 1;
            while (1)
            {
                if (stk.empty())
                    break;
                int num = stk.front();
                stk.pop();
                if (i != boardSize - 1 && bd[i + 1][width] == num && arr[i + 1] == false)
                {
                    bd[i + 1][width] *= 2;
                    arr[i + 1] = 1;
                }
                else
                    bd[i--][width] = num;
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
    {
        backTracking(i, bd, cnt + 1);
    }
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
    cout << gMax;   
    return 0;
}