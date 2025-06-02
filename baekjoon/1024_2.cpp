#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// 등차수열의 합을 기준으로 풀이
// 규칙성을 찾음
// N = x + (x + 1) + (x + 2) + (x + 3) ...... (x + (len - 1))
// N = x * len + (1 ~ (len-1))
// 치환하면
// x = N - (1 ~ len-1) / len
// t : (1 ~ len-1)
// x = N - t / len
// 이때 N - t / len의 나머지가 없으면 x부터 len만큼의 등차수열로 가능

int N, L;

int main()
{
	cin >> N >> L;

	for (int len = L; len <= 100; len++)
	{
		int t = 0;
		for (int i = 1; i < len; i++)
			t += i;
		int numerator = N - t;
		if (numerator < 0 || numerator % len)
			continue;
		int st = numerator / len;
		for (int i = 0; i < len; i++)
			cout << st + i << " ";
		return 0;
	}

	cout << -1;
}