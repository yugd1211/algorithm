#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int N;
int answer = 1000000000;
vector<tuple<int, int, int>> t;

// sort하는 대신 값을 미리 비교하는 방식으로 하여 시간초과 해결 :)

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
		vector<int> v;
		for (int j = 0; j < t.size(); j++)
		{
			if (i == j)
				continue;
			v.push_back(Intimacy(t[i], t[j]));
		}
		sort(v.begin(), v.end());
		answer = min(answer, v[0] + v[1]);
	}
	cout << answer;
}