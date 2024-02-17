#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

int AN;
int BN;

set<int> s;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> AN >> BN;
	for (int i = 0; i < AN; i++)
	{
		int n;
		cin >> n;
		s.insert(n);
	}
	for (int i = 0; i < BN; i++)
	{
		int n;
		cin >> n;
		if (s.find(n) != s.end())
			s.erase(n);
	}
	cout << s.size() << "\n";
	for (auto iter = s.begin(); iter != s.end(); iter++)
		cout << *iter << " ";
}