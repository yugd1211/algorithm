#include <iostream>
using namespace std;
int n;
int arr[1000001];
int tmp[1000001];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int addr = start;
    int bddr = mid + 1;
    for (int i = start; i <= end; i++)
    {
        if (addr > mid)
            tmp[i] = arr[bddr++];
        else if (bddr > end)
            tmp[i] = arr[addr++];
        else if (arr[addr] > arr[bddr])
            tmp[i] = arr[bddr++];
        else
            tmp[i] = arr[addr++];
    }
    for (int i = start; i <= end; i++)
        arr[i] = tmp[i];
}

void merge_sort(int start, int end)
{
    int mid = (start + end) / 2;
    if (start >= end)
        return;
    merge_sort(start, mid);
    merge_sort(mid + 1, end);
    merge(start, end);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}