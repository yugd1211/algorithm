#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string, string> nickTable;
    
    for (int i = 0 ; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string cmd, uid, nick;
        ss >> cmd >> uid >> nick;
        
        if (cmd == "Enter" || cmd == "Change")
            nickTable[uid] = nick; 
    }
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string cmd, uid, nick;
        ss >> cmd >> uid >> nick;
        
        string str = nickTable[uid];
        if (cmd == "Enter")
            str.append("님이 들어왔습니다.");
        else if (cmd == "Leave")
            str.append("님이 나갔습니다.");
        else
            continue;
        answer.push_back(str);
    }
    return answer;
}