#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N; // 500000
int M; // 10

vector<int> v;
bool broken[10];

bool isMake(int number)
{
	if (number == 0)
		return !broken[0];
	while (number > 0)
	{
		if (broken[number % 10])
			return false;
		number /= 10;
	}
	return true;
}

int digit(int number)
{
	int cnt = 1;
	while (number >= 10)
	{
		number /= 10;
		cnt++;
	}
	return cnt;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int curr = 100;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		broken[n] = true;
	}
	int res = abs(N - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		if (isMake(i))
		{
			res = min(res, digit(i) + abs(i - N));
		}
	}

	cout << res;
}