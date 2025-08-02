#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 당연하게도 시간 초과 발생
// 문자열 길이 N이 최대 1000000으로
// find와 erase를 반복하면
// 최악의 경우 O(N^2)
// 특히 find는 O(N * M(찾고자하는 문자열))이 되고
// erase 또한 O(N) 시간이 걸림
// 때문에 시간 초과

void SetIO()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int main()
{
	SetIO();
	string str, bomb;
	cin >> str >> bomb;

	while (str.find(bomb) != string::npos)
		str.erase(str.begin() + str.find(bomb), str.begin() + str.find(bomb) + bomb.size());

	if (str.empty())
		str = "FRULA";

	cout << str;
}