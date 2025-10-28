#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> vec;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int s, e;
		cin >> s >> e;
		vec.push_back({s, e});
	}
	sort(vec.begin(), vec.end());
	int res = 0;

	for (int i = 0; i < vec.size(); i++)
	{
		pair<int, int> curr = vec[i];
		int s, e;
		tie(s, e) = curr;
		pq.push(e);
		if (s >= pq.top())
		{
			pq.pop();
		}
		if (res < pq.size())
			res = pq.size();
	}
	cout << res;
}
