#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    deque<string> dq;
    
    for (int i = 0; i < cities.size(); i++)
        for (int j = 0; j < cities[i].size(); j++)
            cities[i][j] = toupper(cities[i][j]);
    
    for (int i = 0; i < cities.size(); i++)
    {
        string curr_city = cities[i];
        auto f = find(dq.begin(), dq.end(), curr_city);
        if (f != dq.end())
        {
            string tmp = *f;
            dq.erase(f);
            dq.push_back(tmp);
            answer++;
        }
        else
        {
            dq.push_back(curr_city);
            if (dq.size() > cacheSize)
                dq.pop_front();
            answer+=5;
        }
    }
    return answer;
}
