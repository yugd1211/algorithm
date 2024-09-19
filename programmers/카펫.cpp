#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// 가로가 더 긴 직사각형

using namespace std;

vector<int> solution(int brown, int yellow)
{
	vector<int> answer;
	for (int h = 1; h <= yellow; h++)
	{
		if (yellow % h)
			continue;
		int w = yellow / h;
		if (w < h)
			break;
		if (brown == w * 2 + h * 2 + 4)
		{
			answer.push_back(w + 2);
			answer.push_back(h + 2);
			break;
		}
	}
	return answer;
}