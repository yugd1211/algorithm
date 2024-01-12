#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 일단 동생이 이동할 위치를 시간별로 dp로 미리 구해뒀음
// 이제 해당 시간에 동생의 위치에 도달하는 search가 있으면 종료되는 bfs를 만들면되는데
// 문제는 생각나는 방법들이 시간 초과나 메모리 초과가 발생할 것같다.
// 동생이 계속 이동하기 때문에 이전에 풀었던 숨바꼭질 시리즈랑은 아예 다른 방식의 풀이가 필요할것 같다.
// 동생이 움직이기 때문에 동생을 기준으로 search를 그만 두게하면 안된다.

int N, K;
queue<pair<int, int>> q;
int dest[1002];
int board[1000002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;
    dest[0] = K;
    for (int i = 1; i < 1001; i++)
        dest[i] = i + dest[i - 1];
    q.push({N, 0});
    while (!q.empty())
    {
        int point, cnt;
        tie(point, cnt) = q.front();
        q.pop();
    }
}