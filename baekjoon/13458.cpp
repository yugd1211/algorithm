#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int A[1000001];
int B, C;

int main()
{
	long long ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		A[i] -= B;
		ans++;
	}
	for (int i = 0; i < N; i++)
	{
		if (A[i] <= 0)
			continue;
		ans += A[i] / C;
		if (A[i] % C)
			ans++;
	}
	cout << ans;
}