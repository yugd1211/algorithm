#include <algorithm>
#include <iostream>
using namespace std;

// 문제 풀이
// 풀이법에 도달하기 어려웠다.
// 왜냐면 '*'을 board에 찍는것 또한 재귀로 풀려고하니 반복문을 어떻게 작성해야되는지
// 계속 생각했는데, 조건문이 잘 떠오르지 않아서 다른 방식을 찾기로 했다.
// 별을 찍는걸 재귀로 해야겠다고 생각했을떄는 한번에 15번의 재귀를 실행하려 했다.
// 그리고 해당위치에 표시를하고 재귀가 끝나는식인데, 여기까지 코드를 작성했을떄 이렇게하니 N단위로 3개의 트리를 나눠야하는데 이미 3 * 5단위로 재귀를 실행하니까 어떻게 해야할지가 막막했다.
// 그래서 별을찍는건 하드코딩하고 트리별로 나누는걸 재귀를 실행해서 타고 들어가는 방식으로 바꿨다.

int board[7000][7000];
int N;
void Recursion(int x, int y, int size)
{
    if (size <= 3)
    {
        board[x][y + 2] = 1;
        board[x + 1][y + 1] = 1;
        board[x + 1][y + 3] = 1;
        board[x + 2][y + 0] = 1;
        board[x + 2][y + 1] = 1;
        board[x + 2][y + 2] = 1;
        board[x + 2][y + 3] = 1;
        board[x + 2][y + 4] = 1;
        return;
    }
    Recursion(x, y + (size) / 2, size / 2);
    Recursion(x + (size / 2), y, size / 2);
    Recursion(x + (size / 2), y + size, size / 2);
}

int main()
{
    cin >> N;
    Recursion(0, 0, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < ((N * 5) / 3) + (N / 3) - 1; j++)
        {
            if (board[i][j])
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }
}
