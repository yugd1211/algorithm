#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;
int arr[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int cnt = 0;
	int i = 0;
	while (i < N)
	{
		cnt++;
		int tape = arr[i] + L - 1;
		while (i < N && arr[i] <= tape)
			i++;
	}
	cout << cnt;
}