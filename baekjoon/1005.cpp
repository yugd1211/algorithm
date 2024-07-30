#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N, E, K;
int A[1001];
int inDegree[1001];
int graph[1001][1001];

// 문제풀이
// 위상 정렬을 사용해 풀었다.
// 1. 위상 정렬중 indegree가 0인 노드의 리스트를 구하고 해당 노드들 중 최소값을 구해 0인 리스트들에 모두 최소값을 뺀다.
// 1번을 반복적으로 호출하고 indegree가 0인 노드가 없을시 끝낸다.

void init()
{
	fill(inDegree, inDegree + 1001, 0);
	fill(A, A + 1001, 0);
	for (int i = 0; i < 1001; i++)
		fill(graph[i], graph[i] + 1001, 0);
}

void input()
{
	cin >> N >> K;
	init();
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	while (K--)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		inDegree[b]++;
	}
	cin >> E;
}

vector<int> is_zero_in_degree(int N)
{
	vector<int> ret;
	for (int i = 1; i <= N; i++)
		if (!inDegree[i])
			ret.push_back(i);
	return ret;
}

int find_min_num(vector<int> vec)
{
	int num = 100001;
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
		num = min(num, A[*iter]);
	return num;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		int ans = 0;
		input();
		while (1)
		{
			vector<int> zeroInDegree = is_zero_in_degree(N);
			int minNum = find_min_num(zeroInDegree);

			ans += minNum;
			for (auto iter = zeroInDegree.begin(); iter != zeroInDegree.end(); iter++)
			{
				A[*iter] -= minNum;
				if (A[*iter] <= 0)
				{
					inDegree[*iter] = -1;
					for (int i = 1; i <= N; i++)
					{
						if (graph[*iter][i])
						{
							graph[*iter][i] = 0;
							inDegree[i]--;
						}
					}
				}
			}
			if (!A[E])
				break;
		}
		cout << ans << "\n";
	}
}