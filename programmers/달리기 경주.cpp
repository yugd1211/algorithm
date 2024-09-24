#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

// 시간초과
// find함수의 시간복잡도는 O(n)이므로 최대 50000 * 1000000의 시간이 걸린다.
//
// vector<string> solution(vector<string> players, vector<string> callings)
//{
//	vector<string> answer;
//	string tmp;
//	for (int i = 0; i < callings.size(); i++)
//	{
//		auto iter = find(players.begin(), players.end(), callings[i]);
//		tmp = *iter;
//		*iter = *(iter - 1);
//		*(iter - 1) = tmp;
//	}
//	answer = players;
//	return answer;
//}

//
map<string, int> m;
map<int, string> m2;

// 그래서 find의 시간복잡도를 줄이기 위해 탐색에 O(log n)이 걸리는 map을 사용했다.
// 이름으로 몇번째인지를 찾고, 그 전 사람이 누구인지를 파악하기 위해 int를 key값으로 하는 map도 같이 썼다.

vector<string> solution(vector<string> players, vector<string> callings)
{
	vector<string> answer;
	for (int i = 0; i < players.size(); i++)
	{
		m[players[i]] = i;
		m2[i] = players[i];
	}
	for (int i = 0; i < callings.size(); i++)
	{
		int curr = m[callings[i]];
		string nxt_name = m2[curr - 1];
		m2[curr - 1] = callings[i];
		m2[curr] = nxt_name;
		m[nxt_name] = curr;
		m[callings[i]] = curr - 1;
	}
	for (auto &iter : m2)
		answer.push_back(iter.second);
	return answer;
}