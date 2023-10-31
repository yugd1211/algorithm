#include <iostream>
#include <vector>

using namespace std;
int N, S;
int cnt;
int arr[30];
vector<int> vec;

void func(int val, int curr)
{
    if (curr == N)
    {
        if (val == S)
            cnt++;
        return ;
    } 
    func(val + arr[curr], curr + 1);
    func(val, curr + 1);
}

int main()
{
    cin >> N;
    cin >> S;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    func(0, 0);
    if (S == 0) cnt--;
    cout << cnt;
    return 0;
}