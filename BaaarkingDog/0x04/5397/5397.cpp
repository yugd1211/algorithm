#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void printChar(char c)
{
    cout << c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        std::list<char> list = {};
        string line;
        cin >> line;
        std::list<char>::iterator listIter = list.begin();
        for (string::iterator iter = line.begin(); iter != line.end(); iter++)
        {
            if (*iter == '<')
            {
                if (listIter != list.begin())
                    listIter--;
            }
            else if (*iter == '>')
            {
                if (listIter != list.end())
                    listIter++;
            }
            else if (*iter == '-')
            {
                if (listIter != list.begin())
                {
                    listIter = list.erase(std::prev(listIter));
                }
            }
            else
            {
                list.insert(listIter, *iter);
            }
        }
        for_each(list.begin(), list.end(), printChar);
        cout << "\n";
    }
}