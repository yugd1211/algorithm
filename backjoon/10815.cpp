#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		s.insert(n);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		if (s.find(n) != s.end())
			cout << "1 ";
		else
			cout << "0 ";
	}
	return 0;
}