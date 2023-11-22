#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 첫번째 코드 구현방식
// 투포인터를 이용해서 st와 en을 증가시키며 st와 en 사이를 더한값들과 S와 비교하며 st en을 올려가는방식이다.
// 시간초과가 발생했는데 sumSequence함수에서 발생하는것 같다.
// 시간초과를 방지하기 위한 방법으로 st나 en을 올릴때마다 값을 처음부터 구하는것이 아닌
// 더한값을 저장하고 해당 값을 en을 올릴때는 en에 해당하는 값을 더하고
// st를 올릴때는 st에 해당했던 값을 빼주는 방식으로 바꿀 예정

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
    while (st < N && en < N)
    {
        if (en - st + 1 < ret)
        {
            int sum = sumSequence(st, en);
            if (sum < S)
            {
                en++;
                continue;
            }
            else if (sum >= S)
                ret = min(ret, en - st + 1);
        }
        st++;
    }
    if (ret == 200000001)
        cout << 0;
    else
        cout << ret;
    return 0;
}