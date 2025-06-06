#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int T;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		map<string, vector<string>> map;
		for (int i = 0; i < N; i++)
		{
			string name, type;
			cin >> name >> type;
			if (map.find(type) == map.end())
			{
				map[type] = vector<string>(1, name);
			}
			else
				map[type].push_back(name);
		}
		int answer = 1;
		for (auto iter : map)
			answer *= iter.second.size() + 1;
		answer--;
		cout << answer << "\n";
	}
}