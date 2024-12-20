#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
multimap<int, int> m;

int solution(vector<vector<string>> book_time) 
{
    int answer = 0;

    for (int i = 0; i < book_time.size(); i++)
    {
        int startTime = stoi(book_time[i][0].substr(0, 2)) * 60;
        startTime += stoi(book_time[i][0].substr(3, 4));
        
        int endTime = stoi(book_time[i][1].substr(0, 2)) * 60;
        endTime += stoi(book_time[i][1].substr(3, 4)) + 10;
        
        m.insert({startTime, endTime});
    }
    
    int cnt = 0;
    for (int i = m.begin()->first; i < 1441; i++)
    {
        
        if (cnt > answer)
            answer = cnt;
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->first == i)
                cnt++;
        }
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->second == i)
                cnt--;
        }
    }
    return answer;
}