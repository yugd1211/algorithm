#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// loooooooooooooong lonnnnnnnnnnnnng

long long N; // 100000
long long adj[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> adj[i];
	int st = 0;
	int en = N - 1;
	long long rSum = abs(adj[st] + adj[en]);
	long long r1 = adj[st];
	long long r2 = adj[en];
	while (st < en)
	{
		long long sum = adj[st] + adj[en];
		if (abs(sum) < rSum)
		{
			rSum = abs(sum);
			r1 = adj[st];
			r2 = adj[en];
		}
		if (sum < 0)
			st++;
		else
			en--;
	}
	cout << r1 << " " << r2;
}