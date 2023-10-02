#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1;
    string str2;
    int strA[26] = {};
    int ret = 0;

    cin >> str1;
    cin >> str2;
    
    for (int i = 0; i < str1.length(); i++)
        strA[str1[i] - 'a']++;
    for (int i = 0; i < str2.length(); i++)
        strA[str2[i] - 'a']--;
    for (int i = 0; i < 26; i++)
    {
        if (strA[i] < 0)
            strA[i] *= -1;
        ret += strA[i];
    }
    std::cout << ret;
}