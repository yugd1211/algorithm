#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 10의 제곱의 절대값만큼 엘리베이터 이동
// 단 현재 층 + 버튼 값 = 0이면 이동 하지 않음
//
// 이동수체크
// st = story
// en = 0
// 1000 * 2
// 100 * 5
// 10 * 5
// 1 * 4
int answer = 1000000000;

void func(int n, int cnt)
{
	if (n <= 0)
	{
		answer = min(answer, cnt);
		return;
	}
	if (cnt >= answer)
		return;
	func(n / 10, cnt + (n % 10));
	func((n / 10) + 1, cnt + 10 - (n % 10));
}

int solution(int storey)
{
	func(storey, 0);
	return answer;
}