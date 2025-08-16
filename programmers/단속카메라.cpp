#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// 끝지점, 시작지점
vector<pair<int, int>> route;

int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    for (int i = 0; i < routes.size(); i++)
    {
        route.push_back({routes[i][1], routes[i][0]});
    }
    sort(route.begin(), route.end());
    
    for (int i = 0; i < route.size(); i++)
    {
        cout << route[i].first << ", " << route[i].second << "\n";
    }

    while (!route.empty())
    {
        pair<int, int> top = route[0];
        answer++;
        auto srt = route.begin();
        auto end = route.begin() + 1;
        
        int exitIndex = top.first;
        for (int i = 1; i < route.size(); i++)
        {
            if (exitIndex < route[i].second)
                break;
            end++;
        }
        
        route.erase(srt, end);
    }
    
    
    
    return answer;
}