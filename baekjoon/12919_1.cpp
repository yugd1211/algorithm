#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 메모리 초과
// string 의 길이가 50 이하로 별생각없이 bfs로 진행했다.
// 왜 메모리 초과일까 생각해봤는데, 2의 배수로 늘어나니까 결국 2^50 이라 터진거같다.

string add_A(string str)
{
	str.push_back('A');
	return str;
}

string add_B(string str)
{
	str.push_back('B');
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	string A, B;
	cin >> A >> B;
	queue<string> q;

	q.push(A);
	while (!q.empty())
	{
		string topA = q.front();
		q.pop();
		if (topA == B)
		{
			cout << 1;
			return 0;
		}
		else if (topA.size() == B.size())
		{
			continue;
		}
		q.push(add_A(topA));
		q.push(add_B(topA));
	}
	cout << 0;
}