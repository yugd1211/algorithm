#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, L, ans;

int main()
{
	cin >> N >> L;
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());

	int line = 0;
	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		int st, en;
		st = iter->first;
		en = iter->second;

		if (st > line)
			line = st;
		while (line < en)
		{
			line += L;
			ans++;
		}
	}

	cout << ans;
}