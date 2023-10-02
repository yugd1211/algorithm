#include <iostream>

int main()
{
    int numArr[2000001] = {};

    int N = 0;
    std::cin >> N;
    int tmp = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> tmp;
        numArr[tmp] = 1;
    }
    int X;
    std::cin >> X;
    int ret = 0;
    for (int i = 1; i < (X + 1) / 2; i++)
    {
        if (numArr[i] && numArr[X - i])
        {
            ret++;
        }
    }
    std::cout << ret;
}