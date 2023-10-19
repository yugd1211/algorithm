int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응
int n = 7, m = 10; // n = 행의 수, m = 열의 수
#include <iostream>
#include <queue>
#define X first
#define Y second
bool vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;
int main()
{
    std::queue<std::pair <int, int> > Q;
    vis[0][0] = true;
    Q.push(make_pair(0, 0));
    while (!Q.empty())
    {
        pair <int, int> curr = Q.front(); Q.pop();
        std::cout << "( " << curr.X << ", " << curr.Y << " ) ->";
        for (int i = 0; i < 4; i++)
        {
            int nx = curr.X + dx[i];
            int ny = curr.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (board[nx][ny] == false || vis[nx][ny] == true)
                continue;
            vis[nx][ny] = true;
            Q.push(make_pair(nx, ny));
        }
    }
}