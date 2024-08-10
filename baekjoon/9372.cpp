#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 문제 풀이
// 문제를 이해하는데 더 오래걸렸던 문제이다.
// "이번 방학 동안의 비행 스케줄이 주어졌을 때, 상근이가 가장 적은 종류의 비행기를 타고 모든 국가들을 여행할 수 있도록 도와주자."
// "상근이가 한 국가에서 다른 국가로 이동할 때 다른 국가를 거쳐 가도(심지어 이미 방문한 국가라도) 된다".
// 이 두문장때문에 헷갈리지만 가장 적은 종류의 비행기라는 것은 해당 정점 a, b간의 간선을 말한다. a > b, b > a를 아무리 왕복해도 cnt는 1만 올라간다.
// 그렇기 때문에 최소 신장 트리를 사용하면 되지만 결과값은 횟수이기 때문에
// 최소 신장 트리의 간선은 N - 1이다.
// 출력은 N - 1을 하면된다.

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int M;
		cin >> M;
		while (M--)
		{
			int u, v;
			cin >> u >> v;
		}
		cout << N - 1 << "\n";
	}
}