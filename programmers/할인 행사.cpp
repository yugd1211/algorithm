#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for (int i = 0; i < discount.size(); i++)
    {
        vector<int> cnt(number);
        for (int j = i; j < i + 10; j++)
        {
            if (j >= discount.size())
                break;
            for (int k = 0; k < want.size(); k++)
            {
                if (want[k] == discount[j])
                {
                    cnt[k]--;
                    break;
                }
            }
        }
        bool b = true;
        for (int i = 0; i < cnt.size(); i++)
        {
            if (cnt[i] > 0)
                b = false;
        }
        if (b)
            answer++;
    }
    return answer;
}