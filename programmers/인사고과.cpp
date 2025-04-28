#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int solution(vector<vector<int>> scores)
{
    int answer = 0;
    int myS1 = scores[0][0];
    int myS2 = scores[0][1];
    int ts = myS1 + myS2;
    multimap<int, pair<int, int>> mm;
    
    for (auto iter : scores)
    {
        int total = iter[0] + iter[1];
        if (total <= ts)
            continue;
        mm.insert({total, {iter[0], iter[1]}});
    }
    
    for (auto iter : mm)
    {
        int s1, s2;
        tie(s1, s2) = iter.second;
        if (myS1 < s1 && myS2 < s2)
            return -1; 
    }
    
    auto iter = mm.begin();
    while (iter != mm.end())
    {
        auto after = mm.upper_bound(iter->first);
        bool isErase = false;
        while (after != mm.end())
        {
            int curS1 = iter->second.first;
            int curS2 = iter->second.second;
            int nxtS1 = after->second.first;
            int nxtS2 = after->second.second;
            if (curS1 < nxtS1 && curS2 < nxtS2)
            {
                mm.erase(iter++);
                isErase = true;
                break;
            }
            after++;
        }
        if (!isErase) ++iter;
    }
    return mm.size() + 1;
}