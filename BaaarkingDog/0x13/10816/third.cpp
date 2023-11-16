#include <iostream>
#include <algorithm>
using namespace std;

// 이진검색을 하긴하지만 첫번째 위치와 마지막 위치를 구하고 둘의 차이로 갯수를 파악하는 방식
// 찾고자하는 수를 찾으면 해당 위치를 기억하고 계속 같은 수를 찾는다.
// 첫번째 위치를 찾고자할떄는 해당 수보다 작은 곳(인덱스가 낮은 쪽)을 찾아야 하므로
// if (A[mid] >= n) 이러한 조건문이다.
// 이진탐색이 좁혀지는 구간을 mid -> 방향이 아니라  <- mid 방향으로 좁혀나가기 위해
// n을 찾았음에도 해당 위치에 end를 지정해서 start지점을 찾는 방식이다.
// 이를 바탕으로 마지막 위치는 이를 반대로 하면된다

int N, M;
int A[500001];

int firstSearch(int n)
{
    int st = 0;
    int en = N - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (A[mid] >= n)
        {
            en = mid - 1;
            if (A[mid] == n)
                ans = mid;
        }
        else
            st = mid + 1;
    }
    return ans;
}

int lastSearch(int n)
{
    int st = 0;
    int en = N - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (A[mid] <= n)
        {
            st = mid + 1;
            if (A[mid] == n)
                ans = mid;
        }
        else
            en = mid - 1;
    }
    return ans;
}

int binarySearch(int n)
{
    int st = firstSearch(n);
    int en = lastSearch(n);
    if (st < 0)
        return 0;
    return en - st + 1;
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