#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int N;
int answer = 1;
map<float, int> m;
int main()
{

	cin >> N;

	m[0.000] = 1;
	for (float i = 1; i <= 1000; i++)
	{
		for (float j = 1; j <= 10 * i; j++)
		{
			if (!m[i / j])
			{
				m[i / j] = i;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		float score;
		cin >> score;
		cout << "score : " << score << ", answer : " << answer << "\n";
		answer = max(answer, m[score]);
	}
	cout << answer;
}