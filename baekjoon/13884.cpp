#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int P;

int main()
{
	cin.tie();
	ios::sync_with_stdio(0);
	cin >> P;
	while (P--)
	{
		int K, N;
		vector<int> vec;
		cin >> K >> N;
		for (int i = 0; i < N; i++)
		{
			int n;
			cin >> n;
			vec.push_back(n);
		}
		int answer = vec.size();
		vector<int> sort_vec(vec);
		sort(sort_vec.begin(), sort_vec.end());

		int curr = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (sort_vec[curr] == vec[i])
			{
				curr++;
				answer--;
			}
		}
		cout << K << " " << answer << "\n";
	}
}
