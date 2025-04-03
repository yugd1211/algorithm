#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int days = remain / speeds[i];
        if (remain % speeds[i])
            days++;
        q.push(days);
    }
    while (!q.empty())
    {
        int cnt = 1;
        int curr = q.front();
        q.pop();
        while (!q.empty() &&curr >= q.front())
        {
            q.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}