#include <iostream>
#include <algorithm>
using namespace std;

int T;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		long long ans = 1;
		int N, M;
		cin >> N >> M;
		int r = 1;
		for (int j = M; j > M - N; j--)
		{
			ans = ans * j;
			ans = ans / r;
			r++;
		}
		cout << ans << "\n";
	}
}