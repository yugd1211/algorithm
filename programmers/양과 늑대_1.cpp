#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
	Node *parent;
	vector<Node *> children;

	bool isWolf;
	int wolfCount;

	Node()
	{
		parent = NULL;
		wolfCount = 0;
		isWolf = false;
	}
};

// info : 노드별 0 = 양, 1 = 늑대
// edges : 부모, 자식

int solution(vector<int> info, vector<vector<int>> edges)
{
	int answer = 0;
	Node *root = new Node();
	Node nodes[18];
	for (int i = 0; i < info.size(); i++)
		nodes[i].isWolf = info[i];

	for (int i = 0; i < edges.size(); i++)
	{
		Node *parent = &nodes[edges[i][0]];
		Node *child = &nodes[edges[i][1]];
		parent->children.push_back(child);
		child->parent = parent;
	}
	multimap<int, Node *> m;
	queue<Node *> q;
	q.push(&nodes[0]);
	while (!q.empty())
	{
		Node *curr = q.front();
		m.insert({curr->wolfCount, curr});
		q.pop();
		for (int i = 0; i < curr->children.size(); i++)
		{
			Node *child = curr->children[i];
			q.push(child);
			child->wolfCount = curr->wolfCount + child->isWolf;
		}
	}

	for (auto iter : m)
	{
		Node *curr = iter.second;
		if (!curr->isWolf)
			answer++;
		if (answer <= iter.first)
			break;
	}

	return answer;
}