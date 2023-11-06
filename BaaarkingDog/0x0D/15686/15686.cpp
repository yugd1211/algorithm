#include <iostream>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
// 첫번째 트라이에 시간초과 발생
// 해결법은 combine 함수에 idx 인자를 줌으로써 다음 인덱스부터 curr을 쌓아가는 방식으로 수정
// 원래 이렇게 해야됐는데 예시를 통과해서 간과하고 있었다.

using namespace std;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
int N, M;
int gMin = 10000000;
int board[51][51];

int chickenDistance(pair<int, int> home, pair<int, int> chicken)
{
    int a = abs(home.X - chicken.X);
    int b = abs(home.Y - chicken.Y);
    return a + b;
}

void combine(vector<pair<int, int>> curr, int currIdx)
{
    if (curr.size() == M)
    {
        int cityDis = 0;
        for (int homeIdx = 0; homeIdx < home.size(); homeIdx++)
        {
            int home_min = 10000000;
            for (int chickenIdx = 0; chickenIdx < curr.size(); chickenIdx++)
                home_min = min(chickenDistance(home[homeIdx], curr[chickenIdx]), home_min);
            cityDis += home_min;
        }
        gMin = min(gMin, cityDis);
        return;
    }

    for (int i = currIdx; i < chicken.size(); i++)
    {
        curr.push_back(make_pair(chicken[i].X, chicken[i].Y));
        combine(curr, i + 1);
        curr.pop_back();
    }
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
            if (board[i][j] == 1)
                home.push_back(make_pair(i, j));
            else if (board[i][j] == 2)
                chicken.push_back(make_pair(i, j));
        }
    }
    combine(vector<pair<int, int>>(), 0);
    cout << gMin;
    return 0;
}
