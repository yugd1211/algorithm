#include <iostream>
#include <algorithm>
using namespace std;

// 내장 find 함수는 시간 초과

int N, M;
int A[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    sort(A, A + N);
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        // find 함수는 선형탐색이기 때문에 시간초과
        // cout << std::find(A, A + N, n) << "\n";
        // binary_search함수는 이진탐색을 지원해서 시간복잡도가 logN으로 줄어서 통과
        // 해당 함수는 반환값이 bool으로 해당 수가 있는지 없는지만 확인가능하기 때문에
        // 해당 문제에서만 사용가능
        cout << std::binary_search(A, A + N, n) << "\n";
    }
    return 0;
}