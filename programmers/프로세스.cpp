#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int arr[10];

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int curr = 9;
    // 위치, 우선순위
    queue<pair<int, int>> q;
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({i, priorities[i]});
        arr[priorities[i]]++;
    }
    while (!arr[curr])
        curr--;
    while (!q.empty())
    {
        int pos = q.front().first;
        int pri = q.front().second;
        
        q.pop();

        if (pri == curr)
        {
            arr[curr]--;
            while (!arr[curr])
                curr--;
            answer++;
            if (pos == location)
             return answer;
            continue;
        }
        q.push({pos, pri});
    }
    return answer;
}