#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int N;
vector<tuple<int, int, int>> v;

int res[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int maxSize = 1;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({b, c, a});
	}
	sort(v.begin(), v.end());
	// 종료시간, 강의 번호, 강의실 번호
	priority_queue<
		tuple<int, int, int>,
		vector<tuple<int, int, int>>,
		greater<tuple<int, int, int>>>
		pq;

	for (int i = 0; i < N; i++)
	{
		int st, en, num;
		tie(st, en, num) = v[i];
		if (pq.empty())
		{
			pq.push({en, num, 1});
			res[num] = maxSize;
		}
		else
		{
			int top_en, top_num, top_room;
			tie(top_en, top_num, top_room) = pq.top();
			if (st >= top_en)
			{
				pq.pop();
				pq.push({en, num, top_room});
				res[num] = top_room;
			}
			else
			{
				pq.push({en, num, ++maxSize});
				res[num] = maxSize;
			}
		}
	}
	cout << maxSize << "\n";
	for (int i = 1; i <= N; i++)
		cout << res[i] << "\n";
}