#include <string>
#include <vector>

using namespace std;
int N, M;
int res = -1;
int arr[501][501];

// 첫시도 dfs : 시간 초과
// void dfs(int x, int y, int cnt, vector<vector<int>> &tree)
//{
//     if (x == tree.size())
//     {
//         res = max(res, cnt);
//         return;
//     }
//     cnt += tree[x][y];
//     dfs(x + 1, y, cnt, tree);
//     dfs(x + 1, y + 1, cnt, tree);
// }

// int solution(vector<vector<int>> triangle) {
//     dfs(0, 0, 0, triangle);
//     return res;
// }

// 두번째 첫 배열부터 내려오면서 arr을 채워주는 방식
// 굳이 따지자면 dp의 개념이 첨가되었다.
int solution(vector<vector<int>> triangle)
{
	arr[0][0] = triangle[0][0];
	for (int i = 1; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j - 1 >= 0)
				if (arr[i][j] < arr[i - 1][j - 1] + triangle[i][j])
					arr[i][j] = arr[i - 1][j - 1] + triangle[i][j];
			if (j != triangle[i].size() - 1)
				if (arr[i][j] < arr[i - 1][j] + triangle[i][j])
					arr[i][j] = arr[i - 1][j] + triangle[i][j];
		}
	}
	for (int i = 0; i < triangle[triangle.size() - 1].size(); i++)
	{
		res = max(res, arr[triangle.size() - 1][i]);
	}
	return res;
}