#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long adj[51];
long long answer = 0;
long long N, C, W;
// N : 나무 갯수
// C : 나무 자르는 비용
// W : 가격
//

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> C >> W;
	for (int i = 0; i < N; i++)
		cin >> adj[i];

	sort(adj, adj + N);

	int MAX = adj[N - 1];
	for (int i = 1; i <= MAX; i++)
	{
		long long val = 0;
		for (int j = 0; j < N; j++)
		{
			if (adj[j] / i == 0)
				continue;
			int cnt = adj[j] / i - 1;
			if (adj[j] % i)
				cnt++;
			if (((adj[j] / i * i) * W) - (cnt * C) > 0)
				val += ((adj[j] / i * i) * W) - (cnt * C);
		}
		if (answer < val)
			answer = val;
	}
	cout << answer;
}