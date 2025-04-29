#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int adj[1002][1002];
int N, M;

// 2차원 누적합을 활용한 풀이
// https://tech.kakao.com/posts/488 카카오 풀이법을 보고 풀었음...

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
	int answer = 0;
	N = board.size();
	M = board[0].size();

	//
	for (auto iter : skill)
	{
		int type = iter[0];
		int r1 = iter[1];
		int c1 = iter[2];
		int r2 = iter[3];
		int c2 = iter[4];
		int degree = iter[5];
		int plus = type == 2 ? 1 : -1;

		adj[r1][c1] += degree * plus;
		adj[r2 + 1][c1] += degree * -plus;
		adj[r1][c2 + 1] += degree * -plus;
		adj[r2 + 1][c2 + 1] += degree * plus;
	}

	// 좌측에서 우측으로 수열 합
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < M; j++)
			adj[i][j] = adj[i][j] + adj[i][j - 1];
	}

	// 상단에서 하단으로 수열 합
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			adj[i][j] = adj[i - 1][j] + adj[i][j];
		}
	}

	// 수열합 배열에 기존값 더하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			adj[i][j] += board[i][j];
	}

	// 0보다 큰 값구하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			if (adj[i][j] > 0)
				answer++;
	}

	return answer;
}