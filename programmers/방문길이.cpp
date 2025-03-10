#include <iostream>
#include <set>
#include <string>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int solution(string dirs)
{
	set<pair<pair<int, int>, pair<int, int>>> graph;
	int x = 5, y = 5;

	for (char dir : dirs)
	{
		int d;
		if (dir == 'U')
			d = UP;
		else if (dir == 'D')
			d = DOWN;
		else if (dir == 'R')
			d = RIGHT;
		else if (dir == 'L')
			d = LEFT;

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx > 10 || ny > 10)
			continue;

		pair<int, int> from = {x, y};
		pair<int, int> to = {nx, ny};

		if (graph.find({from, to}) == graph.end())
		{
			graph.insert({from, to});
			graph.insert({to, from});
		}
		x = nx;
		y = ny;
	}
	return graph.size() / 2;
}
