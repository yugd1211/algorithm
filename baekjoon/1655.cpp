#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// 문제풀이
// 시간초과 뜰거 같았지만 일단 해봤다
// 풀이자체는 쉽다. 이진검색트리인 multiset(set이 아닌 multiset인 이유는 같은 수가 여러개 들어오기때문)에 값을 넣고 중간값을 내보내는것
// 값을 넣는것 자체는 O(log(n))이지만 중간값을 찾기 위해 iterator로 중간값까지 가야되기때문에 O(n)이다. 그래서 시간 제한이 0.1초를 넘길것 같았지만 일단해봤다.

int N;
multiset<int> s;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		int cnt = 0;
		cin >> n;
		s.insert(n);

		auto iter = s.begin();

		int end = s.size() % 2 == 1 ? s.size() / 2 : s.size() / 2 - 1;
		if (s.size() != 1)
		{
			for (int i = 0; i < end; i++)
				iter++;
		}
		cout << *iter << "\n";
	}
}