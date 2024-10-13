#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

// 14 22
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    if (enemy.size() <= k)
        return enemy.size();
    answer = k;
    for (int i = 0; i < k; i++)
        q.push(enemy[i]);
    for (int i = k; i < enemy.size(); i++)
    {
        if (q.top() < enemy[i])
        {
            n -= q.top();
            q.pop();
            q.push(enemy[i]);
        }
        else
        {
            n -= enemy[i];
        }
        if (n < 0)
            break;
        answer++;
    }
    return answer;
}