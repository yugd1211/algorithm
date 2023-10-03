#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
#include <iterator>

using namespace std;

void printList(char c)
{
    std::cout << c;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    list<char> list;
    string firstStr;
    int M = 0;

    cin >> firstStr;
    for (string::iterator iter = firstStr.begin(); iter != firstStr.end(); iter++)
        list.push_back(*iter);
    cin >> M;
    cin.ignore();

    std::list<char>::iterator iter = list.end();
    for (int i = 0; i < M; i++)
    {
        string line;
        stringstream ss;
        getline(cin, line);
        ss.str(line);
        ss >> line;
        if (!line.compare("L"))
        {
            if (iter != list.begin())
                iter--;
        }
        else if (!line.compare("D"))
        {
            if (iter != list.end())
                iter++;
        }
        else if (!line.compare("B"))
        {
            if (iter != list.begin())
            {
                std::list<char>::iterator tmp = iter;
                tmp--;
                list.erase(tmp);
            }
        }
        else if (!line.compare("P"))
        {
            char add;
            ss >> add;
            list.insert(iter, add);
        }
        else
            continue;
    }
    for_each(list.begin(), list.end(), printList);
}