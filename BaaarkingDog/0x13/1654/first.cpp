#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 이분탐색으로 k개로 나눠지는 길이를 찾고 해당 길이에서 1씩올려가며 최대 길이를 구하는 방식
// 당연하게도 시간초과 발생

int N, K;
int lan[1000001];

int binarySearch(int st, int en)
{
    int mid = (st + en) / 2;
    int cnt = 0;
    for (int i = 0; i < N; i++)
        cnt += lan[i] / mid;
    if (cnt == K)
    {
        int ret = mid;
        while (1)
        {
            cnt = 0;
            for (int i = 0; i < N; i++)
                cnt += lan[i] / ret;
            if (cnt != K)
                break;
            ret++;
        }
        return ret - 1;
    }
    else if (cnt > K)
        return binarySearch(mid + 1, en);
    else
        return binarySearch(st, mid - 1);
}

int main()
{
    cin >> N;
    cin >> K;
    for (int i = 0; i < N; i++)
        cin >> lan[i];
    sort(lan, lan + N);
    cout << binarySearch(0, lan[0]);
    return 0;
}