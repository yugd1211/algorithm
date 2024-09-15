#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;

vector<char> vec;
vector<string> res;

bool isMandatory(string str)
{
	int vc = 0;
	int cc = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			vc++;
		else
			cc++;
	}
	if (vc >= 1 && cc >= 2)
		return true;
	else
		return false;
}

void BackTracking(string str, int n)
{
	if (str.size() == L)
	{
		if (isMandatory(str))
			res.push_back(str);
		return;
	}
	for (int i = n + 1; i < C; i++)
	{
		str.push_back(vec[i]);
		BackTracking(str, i);
		str.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		char c;
		cin >> c;
		vec.push_back(c);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < C; i++)
	{
		string str;
		str.push_back(vec[i]);
		BackTracking(str, i);
	}
	sort(res.begin(), res.end());
	for (auto nxt : res)
		cout << nxt << "\n";
}