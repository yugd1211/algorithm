#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string S, T;
int ret = 0;

void dfs(string str)
{
	if (str == S)
	{
		ret = 1;
		return;
	}
	else if (str.size() <= S.size())
		return;
	if (str[str.size() - 1] == 'A')
	{
		string tmp = str;
		tmp.erase(tmp.size() - 1);
		dfs(tmp);
	}
	if (str[0] == 'B')
	{
		string tmp = str;
		tmp.erase(tmp.begin());
		reverse(tmp.begin(), tmp.end());
		dfs(tmp);
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> S >> T;

	dfs(T);
	cout << ret;
}