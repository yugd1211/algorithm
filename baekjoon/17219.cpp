#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n, m;
	map<string, string> pwTable;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string site, password;
		cin >> site >> password;
		pwTable[site] = password;
	}

	for (int i = 0; i < m; i++)
	{
		string site;
		cin >> site;
		cout << pwTable[site] << "\n";
	}
}