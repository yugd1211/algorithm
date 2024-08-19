#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int newNum;
int P;
vector<int> vec;
int main()
{

	cin >> N >> newNum >> P;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

	int cnt = 0;
	int ans = 1;
	for (int i = 0; i < N; i++)
	{
		if (newNum < vec[i])
			ans++;
		else if (newNum > vec[i])
			break;
		cnt++;
	}

	if (cnt == P)
		ans = -1;
	if (N == 0)
		ans = 1;

	cout << ans;

	return 0;
}