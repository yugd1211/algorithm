#include <iostream>

int func2(int arr[], int N)
{
    int num[101];
    for (int i = 0; i < 101; i++)
        num[i] = 0;
    for (int j = 0; j < N; j++)
    {
        if (num[100 - arr[j]])
            return 1;
        num[arr[j]] = 1;
    }
    return 0;
}

int main()
{
    funbc2({1, 52, 48}, 3);
    funbc2({50, 42}, 2);
    funbc2({4, 13, 63, 87}, 4);
}