#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int N;
int answer = 1000000000;
vector<tuple<int, int, int>> t;

// 시간 초과
// 간선을 vector에 담고, 이를 sort한다.
// 간선을 만들기 위해 이중 for문 O(N^2)의 시간복잡도가 걸린다.
// 이 간선을 sort하기 때문에 최종 시간복잡도는 O(N^2 log N)이다.

int Intimacy(tuple<int, int, int> a, tuple<int, int, int> b)
{
	int ax, ay, az;
	int bx, by, bz;

	tie(ax, ay, az) = a;
	tie(bx, by, bz) = b;
	return abs(ax - bx) + abs(ay - by) + abs(az - bz);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		t.push_back({x, y, z});
	}

	sort(t.begin(), t.end());
	for (int i = 0; i < t.size(); i++)
	{
		int min1 = 1000000;
		int min2 = 1000000;
		for (int j = 0; j < t.size(); j++)
		{
			if (i == j)
				continue;
			else if (min1 > Intimacy(t[i], t[j]))
			{
				if (min2 > min1)
					min2 = min1;
				min1 = Intimacy(t[i], t[j]);
			}
			else if (min2 > Intimacy(t[i], t[j]))
				min2 = Intimacy(t[i], t[j]);
		}
		answer = min(answer, min1 + min2);
	}
	cout << answer;
}