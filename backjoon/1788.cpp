#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[2000002];
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
	for (int i = 1000000; i >= 0; i--)
		arr[1000000 - i] = arr[1000000 - i + 1] + arr[1000000 - i + 2];
	for (int i = 1000003; i < 2000000; i++)
		arr[1000000 - i] = arr[1000000 - i - 1] + arr[1000000 - i - 2];
	
	cin >> N;
	cout << arr[1000000 + N];
}