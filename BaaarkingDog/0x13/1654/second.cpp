#include <iostream>
#include <algorithm>
using namespace std;

// 이번에는 K 갯수에 만족해도 계속 이진탐색을 진행
//

long N, K;
long lan[10001];

int main()
{
    cin >> K;
    cin >> N;
    for (long i = 0; i < K; i++)
        cin >> lan[i];
    sort(lan, lan + K);
    long st = 1;
    long en = lan[K - 1];
    while (st < en)
    {
        long mid = (st + en + 1) / 2;
        long cnt = 0;
        for (long i = 0; i < K; i++)
            cnt += lan[i] / mid;
        if (cnt >= N)
            st = mid;
        else
            en = mid - 1;
    }
    cout << st;
    return 0;
}