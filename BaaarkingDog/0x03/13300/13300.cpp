#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N = 0;
    int maxRoom = 0;
    std::pair<int, int> totalGrade[7] = {};
    int year = 0;
    int sex = 0;
    int ret = 0;

    std::cin >> N;
    std::cin >> maxRoom;
    for (int i = 0; i < N; i++)
    {
        std::cin >> sex;
        std::cin >> year;
        if (sex == 0)
            totalGrade[year].first++;
        else if (sex == 1)
            totalGrade[year].second++;
    }
    for (int i = 1; i < 7; i++)
    {
        ret += (totalGrade[i].first + maxRoom - 1) / maxRoom;
        ret += (totalGrade[i].second + maxRoom - 1) / maxRoom;
    }
    std::cout << ret;
}