#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int num[1001];
vector<int> two;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    // 아래에서 two를 정렬하기 때문에 num은 정렬할 필요없지않나?
    // 하지만 binary_search할때 정렬되어있는 것을 기준으로 큰수에서 작은수를
    // 뺴고 있기때문에 정렬할 필요가 있다.
    sort(num, num + N);
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            two.push_back(num[i] + num[j]);
    sort(two.begin(), two.end());

    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            if (binary_search(two.begin(), two.end(), num[i] - num[j]))
            {
                cout << num[i];
                return 0;
            }
        }
    }
}