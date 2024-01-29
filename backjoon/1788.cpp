#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long arr[2000002];
int N;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	arr[999999] = 1;
	arr[1000000] = 0;
	arr[1000001] = 1;
	arr[1000002] = 1;
	arr[1000003] = 2;
	for (int i = 1; i < 1000001; i++)
		arr[1000000 - i] = (arr[1000000 - i + 2] - arr[1000000 - i + 1]) % 1000000000;
	for (int i = 1; i < 1000001; i++)
		arr[1000000 + i] = (arr[1000000 + i - 1] + arr[1000000 + i - 2]) % 1000000000;

	cin >> N;
	if (arr[1000000 + N] > 0)
	{
		cout << "1\n";
		cout << arr[1000000 + N];
	}
	else if (arr[1000000 + N] < 0)
	{
		cout << "-1\n";
		cout << abs(arr[1000000 + N]);
	}
	else
	{
		cout << "0\n0";
	}
}