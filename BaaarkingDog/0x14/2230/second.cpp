#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// lower_bound를 사용하는 방법

int N, M;
int A[100001];
int gMin = 2000000001;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    for (int i = 0; i < N; i++)
    {
        // int lower = (*lower_bound(A, A + N, A[i] + M)) - A[i];
        // if (lower > 0)
        //     gMin = min(lower, gMin);
        // 위의 코드는 lower_bound에서 A[i] + M이 찾는 범위안에 없으면 맨마지막을 가리킴
        // 그래서 이 때 쓰레기 값이 나오기 때문에 틀림
        // 그렇기 때문에 lower_bound의 값을 확인해야하는 과정이 필요함
        int lower = lower_bound(A, A + N, A[i] + M) - A;
        if (lower < N)
            gMin = min(A[lower] - A[i], gMin);
    }
    cout << gMin;
}