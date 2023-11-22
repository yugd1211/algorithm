#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 두번째 구현방식
// 이전 방식과 같은 투포인터를 사용하지만 st와 en이 변경될때 저장해뒀던 값을 수정하는 방식

int N, S;
int A[100001];

int sumSequence(int st, int en)
{
    int sum = 0;
    for (int i = st; i <= en; i++)
        sum += A[i];
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ret = 200000001;

    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    int st = 0;
    int en = 0;
    int sum = A[0];
    while (st < N && en < N)
    {
        if (sum < S)
            sum += A[++en];
        else
        {
            ret = min(ret, en - st + 1);
            sum -= A[st++];
        }
    }
    if (ret == 200000001)
        cout << 0;
    else
        cout << ret;
    return 0;
}