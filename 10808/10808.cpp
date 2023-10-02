#include <iostream>

int main()
{
    int num[26];
    char argv[101];
    std::cin >> argv;
    for (int i = 0; i < 26; i++) num[i] = 0;
    for (int i = 0; argv[i]; i++)
    {
        num[argv[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        std::cout << num[i] << " ";
}