#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int M, N;
int ar[11000];
int b[11000];
vector<string> vec;
int main()
{
	cin >> M >> N;
	for (int t = 0; t < M; t++)
	{
		map<int, int> m;
		string current = "";
		int cnt = 0;
		for (int x = 0; x < N; x++)
		{
			cin >> ar[x];
			b[x] = ar[x];
		}
		sort(b, b + N);
		m[b[0]] = cnt++;
		for (int x = 1; x < N; x++)
		{
			if (b[x] != b[x - 1])
				m[b[x]] = cnt++;
		}
		for (int x = 0; x < N; x++)
		{
			int k = m[ar[x]];
			int digit = 0;
			while (k > 0)
			{
				digit++;
				k /= 10;
			}
			for (int y = 0; y < 5 - digit; y++)
				current += "0";
			k = m[ar[x]];
			while (k > 0)
			{
				current += (char)(k % 10 + 48);
				k /= 10;
			}
		}
		vec.push_back(current);
	}
	sort(vec.begin(), vec.end());

	int same_cnt = 1;
	int ans = 0;

	for (int x = 1; x < vec.size(); x++)
	{
		if (vec[x] != vec[x - 1])
		{
			ans += same_cnt * (same_cnt - 1) / 2;
			same_cnt = 1;
		}
		else
			same_cnt++;
	}
	ans += same_cnt * (same_cnt - 1) / 2;

	cout << ans;
}