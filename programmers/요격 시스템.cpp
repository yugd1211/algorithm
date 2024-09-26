#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// 아마 시간초과 vector를 erase하는 시간이 너무길다.
// n = 500000으로 최대 n^2이 발생한다.
// int solution(vector<vector<int>> targets)
//{
//	vector<pair<int, int>> v;
//	queue<pair<int, int>> q;
//	int answer = 0;
//	for (int i = 0; i < targets.size(); i++)
//		v.push_back({targets[i][1], targets[i][0]});
//	sort(v.begin(), v.end());
//	for (int i = 0; i < v.size(); i++)
//		q.push({v[i].first, v[i].second});
//	int st = 0;
//	while (!q.empty())
//	{
//		answer++;
//		int n = q.front().first;
//		q.pop();
//		while (!q.empty() && q.front().second < n)
//		{
//			q.pop();
//		}
//	}
//	return answer;
//}

// erase의 시간복잡도가 O(1)인 queue를 사용했다.
int solution(vector<vector<int>> targets)
{
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	int answer = 0;
	for (int i = 0; i < targets.size(); i++)
		v.push_back({targets[i][1], targets[i][0]});
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		q.push({v[i].first, v[i].second});
	int st = 0;
	while (!q.empty())
	{
		answer++;
		int n = q.front().first;
		q.pop();
		while (!q.empty() && q.front().second < n)
			q.pop();
	}
	return answer;
}

int main()
{
	vector<vector<int>> targets;
	targets.push_back({4, 5});
	targets.push_back({4, 8});
	targets.push_back({10, 14});
	targets.push_back({11, 13});
	targets.push_back({3, 7});
	targets.push_back({1, 4});
	cout << "ans = `" << solution(targets);
}