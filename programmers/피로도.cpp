#include <string>
#include <vector>

using namespace std;
int answer = -1;
vector<vector<int>> d;
bool b[10];
void func(bool b[10], int k, int cnt)
{
	if (answer < cnt)
		answer = cnt;
	for (int i = 0; i < d.size(); i++)
	{
		if (b[i] || k < d[i][0])
			continue;
		b[i] = 1;
		k -= d[i][1];
		func(b, k, cnt + 1);
		b[i] = 0;
		k += d[i][1];
	}
}

int solution(int k, vector<vector<int>> dun)
{
	d = dun;
	func(b, k, 0);
	return answer;
}