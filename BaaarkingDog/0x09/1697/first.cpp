// 메모리초과
// 이전의 bfs 문제에서도 발생했던 부분같다. 
// pair로 cnt를 저장하고 있는데 이부분을 정적 배열을 미리 선언하고 바꾸는 식으로 해야할듯


#include <iostream>
#include <queue>
#define num first
#define cnt second

int N, K;
using namespace std;
int main()
{
    queue<pair <int, int> > Q;
    cin >> N;
    cin >> K;
    Q.push(make_pair(N, 0));
    while (!Q.empty())
    {
        pair<int, int> curr = Q.front();
        Q.pop();
        if (curr.num < 0) continue;
        if (curr.num == K)
        {
            cout << curr.cnt;
            return 0;
        }
        if (curr.num < K)
        {
            Q.push(make_pair(curr.num + 1, curr.cnt + 1));
            Q.push(make_pair(curr.num * 2, curr.cnt + 1));
        }
        Q.push(make_pair(curr.num - 1, curr.cnt + 1));
    }
    return 0;
}