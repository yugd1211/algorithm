#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// 코드를 거의 다 작성하고 있었는데, 마지막에 현재 자료구조로는 도저히 풀수가없어서 일단 멈추고 내일해보려한다..

// add P L G
// P = 문제번호
// L = 난이도
// G = 알고리즘

// solved P
// P = 추천 문제 리스트에서 P를 제거

// recommend G x
// x == 1 : G 알고리즘에서 가장 어려운 문제 출력 (번호가 가장 큰것)
// x == -1 : G 알고리즘에서 가장 쉬운 문제 출력 (번호가 가장 작은것)

// recommend2 x
// x == 1 : 모든 알고리즘에서 가장 어려운 문제 출력
// x == -1 : 모든 알고리즘에서 가장 쉬운 문제 출력

// recommend3 x L
// x == 1 : 모든 알고리즘에서 난이도 L보다 크거나 같은 문제중 가장 쉬운 번호 출력
// x == -1 : 모든 알고리즘에서 난이도 L보다 크거나 같은 문제중 가장 어려운 번호 출력

int N, M;
multiset<int> ms[101];
int pn[100001];
int pa[100001];
multiset<int>::iterator pi[100001];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int P, L, G;
		cin >> P >> L >> G;
		pi[P] = ms[G].insert(L);
		pa[P] = G;
		pn[P] = L;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		if (str.compare("add"))
		{
			int P, L, G;
			cin >> P >> L >> G;
			pi[P] = ms[G].insert(L);
			pa[P] = G;
			pn[P] = L;
		}
		else if (str.compare("solved"))
		{
			int P;
			cin >> P;
			ms[pa[P]].erase(pi[P]);
		}
		else if (str.compare("recommend"))
		{
			int G, x;
			cin >> G >> x;
			if (x == 1)
			{
				cout << *(--ms[G].end()) << "\n";
			}
			else
			{
				cout << *ms[G].begin() << "\n";
			}
		}
		else if (str.compare("recommend2"))
		{
			int x, ans;
			cin >> x;
			if (x == 1)
			{
				ans = 0;
				for (int i = 1; i < 101; i++)
				{
					if (ms[i].empty())
						continue;
					ans = max(ans, *(--ms[i].end()));
				}
			}
			else
			{
				ans = 1000000;
				for (int i = 1; i < 101; i++)
				{
					if (ms[i].empty())
						continue;
					ans = min(ans, *ms[i].begin());
				}
			}
			cout << ans << "\n";
		}
		else if (str.compare("recommend3"))
		{
			int x, L;
			cin >> x >> L;
			if (x == 1)
			{
				int p = 10000;
				int n = 10000;
				for (int i = 1; i < 101; i++)
				{
					if (ms[i].empty())
						continue;
					if (ms[i].lower_bound(L) == ms[i].end())
						cout << -1 << "\n";
					else
					{
						// L난이도를 찾았지만 해당 번호를 찾을 수가없다.....
						// ms를 바꾸든 난이도 - 번호를 저장하든 해야할듯....
						// if (*ms[i].lower_bound(L) <= p)
						// n = min(n, )
					}
				}
			}
			else
			{
			}
		}
	}
}