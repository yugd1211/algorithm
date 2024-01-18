#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int vis[200002];

// 대소 비교함수

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
// pq;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> K;
    pq.push({0, K});
    // vis[] = 0;
    while (!pq.empty())
    {
        int curr, h;
        tie(h, curr) = pq.top();
        pq.pop();
        // cout << curr << "\n";
        if (curr == N)
        {
            cout << h << "\n";
            break;
        }
        if (curr && !(curr % 2) && !vis[curr / 2])
        {
            pq.push({h, curr / 2});
            vis[curr / 2] = vis[curr];
        }
        if (curr + 1 <= 100000 && !vis[curr + 1])
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
