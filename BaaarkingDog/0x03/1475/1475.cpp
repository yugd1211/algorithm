#include <iostream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int num;
    int count[10] = {};
    int div = 0;
    std::cin >> num;
    while (num)
    {
        div = num % 10;
        num = num / 10;
        count[div]++;
    }
    if(count[6] || count[9])
    {
        if ((count[6] + count[9]) % 2)
            count[6]++;    
        count[6] = (count[6] + count[9]) / 2;

    }
    int max = 0;
    count[9] = 0;
    for (int i = 0; i < 9; i++)
    {
        if (max < count[i])
            max = count[i];
    }
    std::cout << max;
}