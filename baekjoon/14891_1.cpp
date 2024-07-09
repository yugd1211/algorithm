#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
#define RIGHT 2
#define LEFT 6

deque<int> gear[4];
int vis[4];
int K;

// 첫번쩨 풀이
// 문제 자체를 제대로 파악하지 못해서 틀렸다.
// 로직은 다음과같다.
// queue에 회전하고자하는 기어와 방향을 push한다.
// 반복문에서 queue에 담겨진 노드르 꺼내서 양옆을 확인하고 양옆의 기어를 회전하고 queue에 해당 기어를 push, 그리고 자기 자신을 회전한다.
// 틀린부분이 어디냐면 양옆의 기어를 먼저 회전한다고 했는데, 해당 양옆의 기어의 양옆또한 먼저 확인을 해야한다.
// 그래서 queue대신 stack으로 하려고 생각했지만, 회전하기전의 값을 가지고 있어야되기 때문에 stack으로 하면 맨끝의 기어가 회전한 뒤의 값들을 가지고 비교하기 때문에 이또한 틀릴것이고
// 결국 재귀함수를 통해 회전하기전 재귀함수를 호출하고 그뒤에 자기자신을 회전하는 방식으로 다시 짜봐야 할것같다.

void clear_vis()
{
	memset(vis, 0, 4);
}

void rotate_gear(int n, int dir)
{
	if (dir == 1)
	{
		gear[n].push_front(gear[n].back());
		gear[n].pop_back();
	}
	else
	{
		gear[n].push_back(gear[n].front());
		gear[n].pop_front();
	}
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char n;
			cin >> n;
			gear[i].push_back(n - '0');
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		queue<pair<int, int>> q;
		int g, d; // 몇번째 톱니, 방향 : 1 = 시계, -1 = 반시계
		cin >> g >> d;
		q.push({g - 1, d});
		clear_vis();
		while (!q.empty())
		{
			tie(g, d) = q.front();
			q.pop();
			if (vis[g])
				continue;
			vis[g] = 1;
			if (g == 0)
			{
				if (gear[0][RIGHT] != gear[1][LEFT] && !vis[1])
				{
					rotate_gear(1, d * -1);
					q.push({1, d * -1});
				}
			}
			else if (g == 1)
			{
				if (gear[1][RIGHT] != gear[2][LEFT] && !vis[2])
				{
					rotate_gear(2, d * -1);
					q.push({2, d * -1});
				}
				if (gear[1][LEFT] != gear[0][RIGHT] && !vis[0])
				{
					rotate_gear(0, d * -1);
					q.push({0, d * -1});
				}
			}
			else if (g == 2)
			{
				if (gear[2][RIGHT] != gear[3][LEFT] && !vis[3])
				{
					rotate_gear(3, d * -1);
					q.push({3, d * -1});
				}
				if (gear[2][LEFT] != gear[1][RIGHT] && !vis[1])
				{
					rotate_gear(1, d * -1);
					q.push({1, d * -1});
				}
			}
			else if (g == 3)
			{
				if (gear[3][LEFT] != gear[2][RIGHT] && !vis[2])
				{
					rotate_gear(2, d * -1);
					q.push({2, d * -1});
				}
			}
			rotate_gear(g, d);
		}
	}
	cout << (gear[0][0] == 1 ? 1 : 0) +
				(gear[1][0] == 1 ? 2 : 0) +
				(gear[2][0] == 1 ? 4 : 0) +
				(gear[3][0] == 1 ? 8 : 0);
}