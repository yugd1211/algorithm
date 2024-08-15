#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int ans;
int A[9];
int vis[9];
vector<int> v;

void func()
{
	if (v.size() == N)
	{
		int cnt = 0;
		for (int i = 0; i < N - 1; i++)
			cnt += abs(v[i] - v[i + 1]);
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (vis[i])
			continue;
		vis[i] = 1;
		v.push_back(A[i]);
		func();
		v.pop_back();
		vis[i] = 0;
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	func();
	cout << ans;
}