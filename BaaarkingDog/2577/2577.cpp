#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int num[3] = {};
    int ret[10] = {};
    for (int i = 0; i < 3; i++)
        std::cin >> num[i];
    int sum = num[0] * num[1] * num[2];
    int div = 0;
    while (sum)
    {
        div = sum % 10;
        sum = sum / 10;
        ret[div]++;
    }
    for (int i = 0; i < 10; i++)
        std::cout << ret[i] << "\n";

}