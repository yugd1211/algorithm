#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L;
int A[1001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N);

	for (int i = 0; i < N; i++)
	{
		if (A[i] <= L)
			L++;
		else
			break;
	}
	cout << L;
}