#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 기존 코드 :  시간초과
double GetDistance(long long a, long long b)
{
	return sqrt(a * a + b * b);
}

long long solution(int k, int d)
{
	long long answer = 0;
	for (int i = 0; i <= d; i += k)
	{
		answer += GetDistance(i, j) / k;
		answer++;
	}
	return answer;
}
//////////////////////////////////

////////////////////////////////
///////////////////////////////
// 아래는 시간초과를 피하기 위해 n^2 에서 n으로 시간복잡도를 줄인코드

long long solution(int k, int d)
{
	long long answer = d / k + 1;
	for (long long i = 0; i < d; i += k)
		answer += (long long)sqrt(1LL * d * d - i * i) / k;
	return answer;
}