#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int ascii[26] = {};
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;
        bool flag = 0;
        for (int i = 0; i < str1.length(); i++)
            ascii[str1[i] - 'a']++;
        for (int i = 0; i < str2.length(); i++)
            ascii[str2[i] - 'a']--;
        for (int i = 0; i < 26; i++)
        {
            if (ascii[i])
            {
                flag = 1;
                std::cout << "Impossible\n";
                break;
            }
        }
        if (!flag)
            std::cout << "Possible\n";
    }
}