#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

char arr[3] = {'4', '1', '2'};

string solution(int n) {
    string answer = "";
    
    while (n > 0)
    {
        int curr = n % 3;
        answer.push_back(arr[curr]);
        n /=3;
        if (curr == 0)
            n--;
    }

    reverse(answer.begin(), answer.end());
    return answer;
}