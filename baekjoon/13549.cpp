#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int vis[200002];

// 대소 비교함수에 따라 priority_queue의 root가 바뀌면서 결과값이달라진다.
// first의 hight의 순서만 중요하다고 생각하고 있었는데 second의 대소비교를 정반대로 바꾸니 결과값이 달라졌다.
// 정확한 이유는 모르겠다...

struct ComparePairs
{
    bool operator()(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) const
    {
        return (lhs.first < rhs.first) || ((lhs.first == rhs.first) && (lhs.second > rhs.second));
    }
};

struct compare
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            // first가 같으면 second를 기준으로 내림차순 정렬
            return a.second < b.second;
        }
        // first를 기준으로 오름차순 정렬
        return a.first > b.first;
    }
};

int N, K;
priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               compare>
    pq;
// priority_queue<pair<int, int>,
//                vector<pair<int, int>>,
//                ComparePairs>
//     pq;
// priority_queue<pair<int, int>,
//                vector<pair<int, int>>,
//                greater<pair<int, int>>>
//     pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    pq.push({0, N});
    vis[N] = 0;
    while (!pq.empty())
    {
        int curr, h;
        tie(h, curr) = pq.top();
        pq.pop();
        // cout << curr << "\n";
        if (curr == K)
        {
            cout << h << "\n";
            break;
        }
        int tmp = curr;
        while (tmp && tmp <= 50000 && !vis[tmp * 2])
        {
            pq.push({h, tmp * 2});
            vis[tmp * 2] = vis[tmp];
            tmp *= 2;
        }
        if (curr + 1 <= K && !vis[curr + 1])
        {
            pq.push({h + 1, curr + 1});
            vis[curr + 1] = vis[curr] + 1;
        }
        if (curr - 1 >= 0 && !vis[curr - 1])
        {
            pq.push({h + 1, curr - 1});
            vis[curr - 1] = vis[curr] + 1;
        }
    }
    for (int i = 1000; i < K + 10; i++)
        cout << vis[i] << " ";
}
