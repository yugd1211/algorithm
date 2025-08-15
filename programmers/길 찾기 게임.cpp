#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

const int MAX = 1000000;

int l[100001];
int r[100001];
pair<int, int> nodeInfos[100001];
vector<vector<int>> answer(2);

void Preorder(int root)
{
	answer[0].push_back(root);
	if (l[root])
		Preorder(l[root]);
	if (r[root])
		Preorder(r[root]);
}

void Postorder(int root)
{
	if (l[root])
		Postorder(l[root]);
	if (r[root])
		Postorder(r[root]);
	answer[1].push_back(root);
}

void insertNode(int x, int y, int index, int parent)
{
	int px = nodeInfos[parent].first;

	int &child = x < px ? l[parent] : r[parent];

	if (child == 0)
		child = index;
	else
		insertNode(x, y, index, child);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<pair<int, int>> table[100001];

	// 입력
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		int x = nodeinfo[i][0];
		int y = nodeinfo[i][1];
		table[y].push_back({x, i + 1});
		nodeInfos[i + 1] = {x, y};
	}
	// 정렬
	for (int i = 100000; i >= 0; i--)
	{
		if (table[i].empty())
			continue;
		sort(table[i].begin(), table[i].end());
	}

	// 트리 구성
	int parent = MAX;
	int root;
	for (int i = 100000; i >= 0; i--)
	{
		if (table[i].empty())
			continue;
		int y = i;
		if (parent == MAX)
			root = table[i][0].second;
		else
		{
			vector<pair<int, int>> currNodes = table[y];
			vector<pair<int, int>> parentNodes = table[parent];
			int pn = 0;
			for (int i = 0; i < currNodes.size(); i++)
			{
				int ci = currNodes[i].second;
				int cx = currNodes[i].first;
				int cy = y;
				insertNode(cx, cy, ci, root);
			}
		}
		parent = y;
	}

	// 전후위 순회
	Preorder(root);
	Postorder(root);
	return answer;
}