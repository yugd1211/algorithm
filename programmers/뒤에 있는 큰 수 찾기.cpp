#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

int arr[1000001];
using namespace std;

vector<int> solution(vector<int> numbers) 
{
    vector<int> answer;
    stack<pair<int, int>> stk;
    fill(arr, arr + 1000001, -1);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        while (!stk.empty() && stk.top().second < numbers[i])
        {
            arr[stk.top().first] = numbers[i];
            stk.pop();
        }
        stk.push({i, numbers[i]});
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(arr[i]);
    }
    return answer;
}