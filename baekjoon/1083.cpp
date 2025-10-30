#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int A[51];
int S;

void swap(int *a, int *b)
{
	int *tmp = a;
	a = b;
	b = tmp;
}

int findBicNum(int st)
{
	// 크기, 인덱스
	vector<pair<int, int>> tmp;
	for (int i = st; i < N; i++)
		tmp.push_back({A[i], i});

	sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
	for (int i = 0; i < tmp.size(); i++)
	{
		if (S >= tmp[i].second - st)
			return tmp[i].second;
	}
	return st;
}

bool isSort()
{
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] < A[i + 1])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> S;

	int curr = 0;

	while (S > 0 && !isSort())
	{
		int n = findBicNum(curr) - curr;
		S -= n;

		for (int i = curr + n; i > curr; i--)
		{
			swap(A[i], A[i - 1]);
		}
		curr++;
	}

	for (int i = 0; i < N; i++)
		cout << A[i] << " ";
}