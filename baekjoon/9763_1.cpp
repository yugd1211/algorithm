#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

// 초기 코드
// 시간 초과
// N = 10000
// O(N^3)으로 1000000000000 회의 연산에 의해 시간초과가 발생
int N;
int answer = 1000000000;
vector<tuple<int, int, int>> t;

int Comp(int a, int b, int c)
{
	int x1, y1, z1;
	int x2, y2, z2;
	int x3, y3, z3;
	tie(x1, y1, z1) = t[a];
	tie(x2, y2, z2) = t[b];
	tie(x3, y3, z3) = t[c];
	vector<int> v;
	v.push_back(abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2));
	v.push_back(abs(x1 - x3) + abs(y1 - y3) + abs(z1 - z3));
	v.push_back(abs(x2 - x3) + abs(y2 - y3) + abs(z2 - z3));

	sort(v.begin(), v.end());

	return v[0] + v[1];
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		t.push_back({x, y, z});
	}

	for (int i = 0; i < t.size() - 2; i++)
	{
		for (int j = i + 1; j < t.size() - 1; j++)
		{
			for (int k = j + 1; k < t.size(); k++)
				answer = min(answer, Comp(i, j, k));
		}
	}

	cout << answer;
}
