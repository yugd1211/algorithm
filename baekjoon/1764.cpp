#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

string arr[1000000];
unordered_set<string> uSet;
set<string> s;
string str;
int N, M;

void input()
{
	cin >> N >> M;

	for (int i = 0; i < N + M; i++)
		cin >> arr[i];
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	input();
	for (int i = 0; i < N; i++)
		uSet.insert(arr[i]);
	for (int i = N; i < N + M; i++)
		if (uSet.count(arr[i]))
			s.insert(arr[i]);
	cout << s.size() << "\n";
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << "\n";
}