#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    for (int h = 1; h <= citations.size(); h++)
    {
        int idx = lower_bound(citations.begin(), citations.end(), h) - citations.begin();
        int count = citations.size() - idx;
        
        if (count >= h) 
            answer = h;
    }
    return answer;
}