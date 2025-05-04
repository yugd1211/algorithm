#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string solution(string s)
{
    
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    
    if (isalpha(s[0])) s[0] = toupper(s[0]);
    
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == ' ')
        {
            if (isalpha(s[i + 1])) s[i + 1] = toupper(s[i + 1]);
        }
    }
    return s;
}