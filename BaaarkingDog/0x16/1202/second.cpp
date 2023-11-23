#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N, K;
long long total;

// 이전의 풀이법에서의 문제는 보석에 주어진 정보는 무게와 가격으로 2개로 이를 확인하는 시간은 제곱이였다.
// 그렇기 떄문에 시점을 아예 바꿔야한다.
// 가방을 기준으로 해당 무게에 담을 수 있는 것 중 제일 비싼 보석을 담는 것이 아닌
// 보석을 기준으로 제일 비싼보석부터 담을 수 있는 가방중 제일 작은 가방에 담는 것

// 계속 틀리길래 왜그런지 몰라서 해멨는데, set대신 multiset으로 해결..

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    multiset<int> bag;
    multimap<int, int> jewelry;
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
    {
        int M;
        int V;
        cin >> M;
        cin >> V;
        jewelry.insert({V, M});
    }
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        bag.insert(n);
    }
    for (auto iter = jewelry.rbegin(); iter != jewelry.rend(); iter++)
    {
        multiset<int>::iterator tmp = bag.lower_bound(iter->second);
        if (tmp != bag.end())
        {
            bag.erase(tmp);
            total += iter->first;
        }
    }
    cout << total;
}