#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int N; // 10
int M; // 50

// 가격이 제일 작은 순으로 정렬함
vector<pair<int, int>> minCostVec;

// 번호가 제일 큰 순으로 정렬
vector<pair<int, int>> maxValueVec;

map<int, int> m;

int FindNumberReturnCost(int number)
{
	for (int i = 0; i < maxValueVec.size(); i++)
	{
		if (maxValueVec[i].first == number)
			return maxValueVec[i].second;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	// 갈수록 번호는 높아지기 떄문에 해당 번호보다 비싼 번호들은 모두 제외한다
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		while (m.lower_bound(n) != m.end())
		{
			m.erase(m.lower_bound(n));
		}

		m[n] = i;
	}
	cin >> M;

	// 제외된것들중 가격이 제일 싼 배열로 정렬
	for (auto &[cost, num] : m)
	{
		minCostVec.push_back({cost, num});
		maxValueVec.push_back({num, cost});
	}

	sort(minCostVec.begin(), minCostVec.end());
	sort(maxValueVec.begin(), maxValueVec.end(), greater<pair<int, int>>());
	if (M == minCostVec[0].first)
	{
		cout << minCostVec[0].second;
		return 0;
	}

	string str;

	// 가격이 제일 싼 번호로 모두 채우기
	while (M >= minCostVec[0].first)
	{
		if (str.size() == 0 && minCostVec[0].second == 0 && minCostVec[1].first <= M)
		{
			str.push_back(minCostVec[1].second + '0');
			M -= minCostVec[1].first;
		}
		else
		{
			str.push_back(minCostVec[0].second + '0');
			M -= minCostVec[0].first;
		}
	}

	// 앞부터 제일 높은 번호로 그리디
	for (int i = 0; i < str.size() && M > 0; i++)
	{
		char currChar = str[i];
		int currCost = FindNumberReturnCost(currChar - '0');
		for (int j = 0; j < maxValueVec.size(); j++)
		{
			if (currCost + M >= maxValueVec[j].second)
			{
				str[i] = maxValueVec[j].first + '0';
				M -= maxValueVec[j].second - currCost;
				break;
			}
		}
	}

	if (str[0] == '0')
		cout << '0';
	else
		cout << str;
}