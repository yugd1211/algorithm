#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

int N, K;
long long total;

// 문제 풀이
// 보석은 multimap, 가방은 set에 각각 담아준다.
// 보석은 무게를 key값으로 정렬한다.
// 가방의 제일 작은 무게부터 해당 무게보다 작은 보석들을 모두 확인하면 제일 큰 무게를 담아준다.
// 하지만 이때 해당 무게보다 작은 보석들을 모두 확인해야하기 때문에 여기서 시간복잡도가 n2이 발생한다.

// 결과는 시간 초과
// while문의 시간복잡도가 O(M * M)이기 때문에 시간 초과는 예상하긴했다..

int main()
{
    set<int> bag;
    multimap<int, int> jewelry;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
    {
        int M;
        int V;
        cin >> M;
        cin >> V;
        jewelry.insert({M, V});
    }
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        bag.insert(n);
    }
    for (set<int>::iterator iter = bag.begin(); iter != bag.end(); iter++)
    {
        multimap<int, int>::iterator upper = jewelry.upper_bound(*iter);
        multimap<int, int>::iterator most = jewelry.end();
        while (upper-- != jewelry.begin())
        {
            if (most == jewelry.end() || most->second < upper->second)
                most = upper;
        }
        total += most->second;
        if (most != jewelry.end())
            jewelry.erase(most);
    }
    cout << total;
}