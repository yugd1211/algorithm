#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// stl의 함수들을 사용하지않고 직접 모든걸 구현한 경우
// 이진검색과 중복제거를 직접구현

int N;
int num[1000001];
int sortNum[1000001];
int tmp[1000001];
int binarySearch(int st, int en, int n)
{
    int mid = (st + en) / 2;
    if (st > en)
        return -1;
    if (sortNum[mid] == n)
        return mid;
    else if (sortNum[mid] > n)
        return binarySearch(st, mid - 1, n);
    else
        return binarySearch(mid + 1, en, n);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    for (int i = 0; i < N; i++)
        tmp[i] = num[i];

    sort(tmp, tmp + N);
    sortNum[0] = tmp[0];
    int size = 1;
    for (int i = 1; i < N; i++)
        if (tmp[i] != tmp[i - 1])
            sortNum[size++] = tmp[i];
    for (int i = 0; i < N; i++)
        cout << binarySearch(0, size - 1, num[i]) << " ";
    return 0;
}