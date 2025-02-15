#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    int alp[27];
    
    fill(alp, alp + 27, -1);
    
    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            if (alp[keymap[i][j] - 'A'] == -1 || alp[keymap[i][j] - 'A'] > j + 1)
                alp[keymap[i][j] - 'A'] = j + 1;
        }
    }
    
    for (int i = 0; i < targets.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            if (alp[targets[i][j] - 'A'] == -1)
            {
                cnt = -1;
                break;
            }
            cnt += alp[targets[i][j] - 'A'];
        }
        answer.push_back(cnt);
    }
    return answer;
}