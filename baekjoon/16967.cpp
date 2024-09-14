#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int H, W, X, Y;

int adj[606][606];

void input()
{
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < H + X; i++)
		for (int j = 0; j < W + Y; j++)
			cin >> adj[i][j];
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	input();
	for (int i = X; i < H + X; i++)
		for (int j = Y; j < W + Y; j++)
			adj[i][j] -= adj[i - X][j - Y];

	// 출력
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cout << adj[i][j] << " ";
		cout << "\n";
	}
}
