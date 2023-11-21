#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 중복제거는 unique 함수와 erase함수를 통해 제거하고
// 이진검색은 lower_bound 함수를 통해 실행한다.
int N;
int num[1000001];

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        vec[i] = num[i];
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < N; i++)
        cout << lower_bound(vec.begin(), vec.end(), num[i]) - vec.begin() << " ";
    return 0;
}