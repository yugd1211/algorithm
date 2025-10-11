#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N; // 500000
int M; // 1000000

int p[500001];

int findParent(int c)
{
	if (p[c] == c)
		return c;
	return p[c] = findParent(p[c]);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		
		int parentU = findParent(u);
		int parentV = findParent(v);
		
		if (parentU == parentV)
		{
			cout << i + 1 << "\n";
			return 0;
		}
		
		p[parentU] = parentV;
	}

	cout << 0;
}
