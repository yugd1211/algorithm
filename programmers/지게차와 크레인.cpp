#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Init(vector<string> &storage)
{
	for (int i = 0; i < storage.size(); i++)
	{
		storage[i].insert(storage[i].begin(), '-');
		storage[i].push_back('-');
	}
	string str;
	for (int i = 0; i < M; i++)
		str.push_back('-');
	storage.insert(storage.begin(), str);
	storage.push_back(str);
}

void PrintArray(vector<string> &storage)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (storage[i][j] != '-')
				cout << storage[i][j];
		}
		cout << "\n";
	}
}

void Crain(vector<string> &storage, char curr)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (storage[i][j] == curr)
				storage[i][j] = '-';
		}
	}
}

void ForkLift(vector<string> &storage, char curr)
{
	int vis[53][53] = {0};
	queue<pair<int, int>> q;
	q.push({0, 0});
	vis[0][0] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			if (vis[nx][ny])
				continue;
			vis[nx][ny] = 1;
			if (storage[nx][ny] == curr)
				storage[nx][ny] = '-';
			else if (storage[nx][ny] == '-')
				q.push({nx, ny});
		}
	}
}

int solution(vector<string> storage, vector<string> requests)
{
	int answer = 0;
	N = storage.size() + 2;
	M = storage[0].size() + 2;
	Init(storage);

	for (int i = 0; i < requests.size(); i++)
	{
		if (requests[i].size() == 1)
		{
			ForkLift(storage, requests[i][0]);
		}
		else
		{
			Crain(storage, requests[i][0]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (storage[i][j] != '-')
				answer++;
		}
	}
	return answer;
}