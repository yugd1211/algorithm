#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<string> g_set;

vector<int> solution(int n, vector<string> words)
{
    int cnt = 0;
    
    char prev = words[0][0];
    for (int i = 0; i < words.size(); i++)
    {
        if (g_set.find(words[i]) != g_set.end() || prev != words[i][0])
            return {(cnt % n) + 1, (cnt / n) + 1};
        g_set.insert(words[i]);
        prev = words[i][words[i].size() - 1];
        cnt++;
    }
    return {0, 0};
}