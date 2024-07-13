#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> vec;
priority_queue<pair<int, int>> pq;

int N;
// int most;
pair<int, int> most;
bool is_growing = true;
long long ans;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int L, H;
		cin >> L >> H;
		vec.push_back({L, H});
		if (most.second < H)
			most = max(most, H);
	}
	sort(vec.begin(), vec.end());
	int prev = 0;
	for (int i = 1; i < vec.size(); i++)
	{
		int wight;
		int hight;
		tie(wight, hight) = vec[i];
		if (hight == most)
			is_growing = false;
		if (is_growing)
		{
			if (vec[i].second > vec[prev].second)
			{
				int diff = vec[i].first - vec[prev].first;
				ans += diff * vec[prev].second;
				prev = i;
			}
		}
		else
		{
			ans += most;
			prev = i;
			break;
		}
	}
}