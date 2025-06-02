#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

// N : 총합
// L : 길이

// 시간 초과
// 순차합을 활용한 풀이였지만 결국 N^2으로 시간초과

int N, L;
queue<int> q;

int main()
{
	queue<int> retQ;
	cin >> N >> L;

	int sum = 0;
	// L까지 더함
	for (int i = 0; i < L; i++)
	{
		sum += i;
		q.push(i);
	}
	if (sum > N)
	{
		cout << -1;
		return 0;
	}
	for (int i = L; i < N; i++)
	{
		while (sum > N)
		{
			sum -= q.front();
			q.pop();
		}
		if (q.size() < L)
			break;
		if (sum == N)
		{
			retQ = q;
		}
		if (sum <= N)
		{
			sum += i;
			q.push(i);
		}
	}
	if (retQ.empty())
		cout << -1;
	else
	{
		while (!retQ.empty())
		{
			cout << retQ.front() << " ";
			retQ.pop();
		}
	}
	return 0;
}