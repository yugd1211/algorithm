#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
priority_queue<int> pq;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			if (pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(n);
		}
	}
}