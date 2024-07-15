#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> vec;
int dis[100001];

// 유클리드 호제법을 사용하여 모든 가로수 사이 거리들의 최대 공약수를 구한다.
// 모든 가로수 사이 거리를 최대 공약수로 나눈 값을 더하고 결과를 출력합니다.
// 나무를 심을 때, 다음 나무는 이미 심어져 있으므로 모든 가로수 사이 거리를 최대 공약수로 나눈 값에서 1을 뺀 값을 더해준다.

int euclidean(int a, int b)
{
	if (a < b)
		swap(a, b);
	if (a % b == 0)
		return b;
	else
		return euclidean(b, a % b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	int gcd;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size() - 1; i++)
		dis[i] = vec[i + 1] - vec[i];
	gcd = dis[0];
	for (int i = 0; i < N - 1; i++)
		gcd = euclidean(gcd, dis[i]);
	for (int i = 0; i < N - 1; i++)
		ans += dis[i] / gcd - 1;
	cout << ans;
}