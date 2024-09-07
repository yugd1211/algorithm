#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제 풀이
// 그리디로 풀었다.
// 마감시간 기준으로 내림차순으로 정렬했다.
// curr값을 제일 마감시간이 큰 값으로 초기화하고,
// 모든 일들을 순회하면 해당 curr값에 걸리는 시간을 빼간다.
// 주의할점은 curr값이 마감시간보다 크면 해당 마감시간으로 맞춰줘야한다.
// 마지막일까지 순회를 하고 났을때 curr값이 음수이면 -1을 출력, 양수이면 해당 값을 출력해준다.

int N;
pair<int, int> p[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		p[i] = {b, a};
	}
	sort(p, p + N, greater<pair<int, int>>());
	int curr = p[0].first;
	for (int i = 0; i < N; i++)
	{
		if (curr > p[i].first)
			curr = p[i].first;
		curr -= p[i].second;
	}
	if (curr > 0)
		cout << curr;
	else
		cout << -1;
}

// 2 ~ 5  6 ~ 14 14 ~ 14  15 ~ 20