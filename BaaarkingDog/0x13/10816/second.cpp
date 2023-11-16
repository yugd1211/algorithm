#include <iostream>
#include <algorithm>
using namespace std;

// 이진 검색의 예제로 나온것이기 때문에 이진 검색을 이용해서 푼 코드
// 이진 검색으로 해당 숫자를 찾고 앞뒤로 몇개 있는지 확인하는식
// 첫번째 시도는 시간초과

int N, M;
int A[500001];

int binarySearch(int n)
{
    int st = 0;
    int en = N - 1;
    int ans = 0;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (A[mid] == n)
        {
            ans++;
            int prev = mid - 1;
            int next = mid + 1;
            while (prev >= 0 && A[prev--] == n)
                ans++;
            while (next < N && A[next++] == n)
                ans++;
            return ans;
        }
        if (A[mid] < n)
            st = mid + 1;
        else
            en = mid - 1;
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        cout << binarySearch(n) << " ";
    }

    return 0;
}