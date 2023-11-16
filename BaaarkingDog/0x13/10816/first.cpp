#include <iostream>
#include <algorithm>
using namespace std;

// 딱 처음 문제를 보자마자 카운팅 정렬로 가능할 것 같아서 시도
// 통과

int N, M;
int A[20000002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        A[10000000 - n]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        cout << A[10000000 - n] << " ";
    }

    return 0;
}