#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#include <queue>

using namespace std;

int solution(vector<int> picks, vector<string> minerals)
{
    vector<int> mines;
    int answer = 0;
    // string -> int 값으로 파싱. 크기는 돌 곡괭이 기준으로 파싱함
    for (auto n : minerals)
    {
        if (n == "diamond")
            mines.push_back(25);
        else if (n == "iron")
            mines.push_back(5);
        else if (n == "stone")
            mines.push_back(1);
    }

    while (mines.size() % 5)
    {
        mines.push_back(0);
    }
    
    // 파싱한 값을 처음부터 순서대로 5개씩 자르고, 이들의 총합을 구함
    // 총합을 구하는 이유는 이 값을 기준으로 그리디 알고리즘을 적용해야 하기 때문
    // multimap의 key값을 총합으로, value에는 어떤 값들이 담겨있는지를 알기 위함
    multimap<int, tuple<int, int, int, int, int>, greater<int>> table;
    int j = 0;
    int pickCnt = picks[0] + picks[1] + picks[2];
    for (int i = 0; i < mines.size() && j < pickCnt; i+=5, j++)
    {
        int total = mines[i] + mines[i + 1] + mines[i + 2] + mines[i + 3] + mines[i + 4];
        table.insert({total, {mines[i], mines[i + 1], mines[i + 2], mines[i + 3], mines[i + 4]}});
    }
    queue<int> q;
    
    for (int i = 0; i < 3; i++)
    {
        int n = 0;
        if (i == 0)
            n = 25;
        else if (i == 1)
            n = 5;
        else if (i == 2)
            n = 1;

        for (int j = 0; j < picks[i]; j++)
            q.push(n);
    }

    for (auto iter : table)
    {
        int total = iter.first;
        int mine[5];
        tie(mine[0], mine[1], mine[2], mine[3], mine[4]) = iter.second;
        int currPick = q.front();
        q.pop();
        for (int i = 0; i < 5; i++)
        {
            if (mine[i] == 0)
                continue;
            
            while (mine[i] > 0)
            {
                mine[i] -= currPick;
                answer++;
            }
        }
    }

    return answer;
}