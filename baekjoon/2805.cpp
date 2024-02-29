#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 이분탐색 풀이
// 풀이자체는 어렵지 않았지만 이분탐색이 오랜만이라 인덱스 지정에서 에러가 많이 발생했다.
// l, r의 지정이라거나 while의 조건문이 생각보다 까다로웠다

int N, M;
vector<long long> vec;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	long long l = 0;
	long long r = *(--vec.end());
	long long ans = 0;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 0; i < N; i++)
		{
			if (mid == 0)
				cnt += vec[i] - mid;
			else
			{
				if (vec[i] / mid)
					cnt += vec[i] - mid;
			}
		}
		if (cnt >= M)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	cout << ans;
}