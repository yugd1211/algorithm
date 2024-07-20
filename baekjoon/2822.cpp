#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> A[8];

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	for (int i = 0; i < 8; i++)
	{
		int n;
		cin >> n;
		A[i] = {n, i + 1};
	}
	sort(A, A + 8);
	int ans = 0;
	vector<int> sequence;
	for (int i = 3; i < 8; i++)
	{
		ans += A[i].first;
		sequence.push_back(A[i].second);
	}
	cout << ans << "\n";
	sort(sequence.begin(), sequence.end());
	for (int i = 0; i < sequence.size(); i++)
		cout << sequence[i] << " ";
}