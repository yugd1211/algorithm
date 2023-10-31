#include <iostream>

using namespace std;

int arr[10];
int isused[10];
int N, M;
void func(int curr)
{
    if (M < curr)
    {
        for (int i = 1; i <= M; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return ;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!isused[i])
        {
            arr[curr] = i;
            isused[i] = 1;
            func(curr + 1);
            isused[i] = 0;
        }
    }
}

int main()
{
    cin >> N;
    cin >> M;
    func(1);
    return 0;
}