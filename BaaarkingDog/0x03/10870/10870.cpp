#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N = 0;
    int num[100] = {};
    int v = 0;
    int ret = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        num[i] = n;
    }
    std::cin >> v;
    for (int i = 0; i < N; i++)
    {
        if (num[i] == v)
            ret++;
    }
    std::cout << ret;
}