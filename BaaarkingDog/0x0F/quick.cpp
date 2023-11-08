#include <iostream>
using namespace std;

int n;
int arr[1000001];

void quick_sort(int start, int end)
{
    int pivot = arr[start];
    int l = start + 1;
    int r = end;
    if (end <= start + 1)
        return;
    while (1)
    {
        while (l <= r && arr[l] <= pivot)
            l++;
        while (l <= r && arr[r] > pivot)
            r--;
        if (l > r)
        {
            swap(arr[start], arr[r]);
            break;
        }
        swap(arr[l], arr[r]);
    }
    quick_sort(start, r);
    quick_sort(r + 1, end);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    quick_sort(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\n";
    return 0;
}