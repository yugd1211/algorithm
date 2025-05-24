#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// k = 최상급 , 내림차순
// m = 상자당 갯수

int solution(int k, int m, vector<int> score)
{
	int answer = 0;
	sort(score.begin(), score.end(), greater());
	for (int i = m - 1; i < score.size(); i += m)
		answer += score[i] * m;

	return answer;
}