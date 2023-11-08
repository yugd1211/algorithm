#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[100001];
int cnt[100001];

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N);
    int ret = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (j != 0 && arr[i - 1] == arr[i])
                break;
            if (arr[i] != arr[j])
                break;
            cnt[i]++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (cnt[ret] < cnt[i])
            ret = i;
    }
    cout << arr[ret];
    return 0;
}