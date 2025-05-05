#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) 
{
    set<string> s;
    for (int i = 0; i < phone_book.size(); i++)
        s.insert(phone_book[i]);
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j < phone_book[i].size(); j++)
        {
            string str = phone_book[i].substr(0, j);
            if (s.find(str) != s.end())
                return false;
        }
    }
    return true;
}