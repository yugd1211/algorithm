#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int T;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		long long ans = 0;
		int K;
		cin >> K;
		for (int i = 0; i < K; i++)
		{
			int n;
			cin >> n;
			pq.push(n);
		}
		while (!pq.empty())
		{
			long long n1 = pq.top();
			pq.pop();
			if (pq.empty())
				break;
			long long n2 = pq.top();
			pq.pop();
			ans += n1 + n2;
			pq.push(n1 + n2);
		}
		cout << ans << "\n";
	}
}