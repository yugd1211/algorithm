#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    for (int i = 0; i < name.size(); i++)
        answer += min(abs('A' - name[i]), abs('Z' - name[i] + 1));

    // 최대치
    int cnt = name.size() - 1;
    
    for (int i = 0; i < name.size(); i++)
    {
        int nxt = i + 1;
        while (nxt < name.size() && name[nxt] == 'A')
            nxt++;
        
        cnt = min(cnt, i + (int)name.size() - nxt + min(i, (int)name.size() - nxt));
    }
    answer += cnt;
    return answer;
}