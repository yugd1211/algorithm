#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <tuple>
using namespace std;

int N, M;
int ret = 2000000000;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

vector<pair<int, int>> currentChicken;

void CheckDistance()
{
	int cnt = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int currHomeCount = 1000000000;
		for (int j = 0; j < currentChicken.size(); j++)
		{
			int r1, r2, c1, c2;
			tie(r1, c1) = home[i];
			tie(r2, c2) = currentChicken[j];
			int r = abs(r1 - r2);
			int c = abs(c1 - c2);
			currHomeCount = min(currHomeCount, r + c);
		}
		cnt += currHomeCount;
	}
	ret = min(ret, cnt);
}

void Combi(int index)
{
	if (currentChicken.size() == M)
	{
		CheckDistance();
		return;
	}

	if (index >= chicken.size() || currentChicken.size() + (chicken.size() - index) < M)
	{
		return;
	}

	currentChicken.push_back(chicken[index]);
	Combi(index + 1);
	currentChicken.pop_back();

	Combi(index + 1);
}

int main()
{
	// input
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;
			if (n == 1)
				home.push_back({i, j});
			else if (n == 2)
				chicken.push_back({i, j});
		}
	}
	Combi(0);
	cout << ret;
}