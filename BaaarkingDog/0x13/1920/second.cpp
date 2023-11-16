#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100001];

bool my_binary_search(int n)
{
    int left = 0;
    int right = N - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (A[mid] == n)
            return 1;
        if (A[mid] < n)
            left = mid + 1;
        else
            right = mid - 1;
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
    cin >> M;
    sort(A, A + N);
    for (int i = 0; i < M; i++)
    {
        int n;
        cin >> n;
        cout << my_binary_search(n) << "\n";
    }
    return 0;
}