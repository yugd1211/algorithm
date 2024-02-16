#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int n;
			cin >> n;
			if (pq.size() < N)
				pq.push(n);
			else if (pq.top() < n)
			{
				pq.pop();
				pq.push(n);
			}
		}
	}
	cout << pq.top();
}