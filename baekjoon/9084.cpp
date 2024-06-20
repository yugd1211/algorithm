#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	// T : 테스트 케이스
	// N : 동전 수
	// Ns : 동전들
	// M : 만들어야 할 금액

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		vector<int> vec;
		for (int j = 0; j < N; j++)
		{
			int coin;
			cin >> coin;
			vec.push_back(coin);
		}
		int dest;
		cin >> dest;
	}
}
