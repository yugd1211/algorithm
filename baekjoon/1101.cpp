#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;

int main()
{
	int ans;
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<vector<pair<int, int>>> cards;
	vector<pair<int, int>> oneCards;

	// 입력
	cin >> N >> M;
	ans = N - 1;
	for (int i = 0; i < N; i++)
	{
		cards.push_back(vector<pair<int, int>>());
		for (int j = 0; j < M; j++)
		{
			int n;
			cin >> n;
			if (n != 0)
				cards[i].push_back({j, n});
		}
	}

	// 카드가 없거나 하나밖에없는 박스를 선별
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i].size() == 1)
			oneCards.push_back(cards[i][0]);
		else if (cards[i].size() == 0)
			ans--;
	}

	// 카드 하나만 있는 박스가 있으면 조커 박스에 합치지 않아도되기때문에 cnt--;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < oneCards.size(); j++)
		{
			if (oneCards[j].first == i)
			{
				ans--;
				break;
			}
		}
	}

	if (ans < 0)
		cout << 0;
	else
		cout << ans;
}
