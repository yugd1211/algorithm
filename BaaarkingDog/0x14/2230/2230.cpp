#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 구현 방법
// 일단 수열을 정렬시킨다.
// 첫 두 수의 차이를 확인한다.
// 두 수의 차이가 M이 될때 까지 두번째 포인터를 옮긴다.
// 두 수의 차이가 M 이상이 될때 min 값과 비교해서 더작은수를 min으로 두고
// 첫번째 포인터를 한칸 옮긴다.
// 두번쩌 포인터의 수와 비교한다.
// 두번째 포인터의 수와 첫번째 포인터의 수의 차이가 M이상이 될때까지 두번째 포인터를 옮긴다.
// 반복

int N, M;
int A[100001];
int gMin = 2000000001;

int main()
{
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    int fp = 0;
    int sp = 1;
    while (fp < N - 1 && sp < N)
    {
        if (A[sp] - A[fp] > M)
        {
            gMin = min(gMin, A[sp] - A[fp]);
            fp++;
            continue;
        }
        else if (A[sp] - A[fp] == M)
        {
            gMin = M;
            break;
        }
        sp++;
    }
    cout << gMin;
}