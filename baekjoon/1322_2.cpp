#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long X, K;
	cin >> X >> K;
	long long answer = 0;
	long long kBitPos = 0;
	long long bitPos = 0;
	while (kBitPos < 64)
	{
		if ((X & (1LL << bitPos)) == 0)
		{
			if (K & (1LL << kBitPos))
				answer |= (1LL << bitPos);
			kBitPos++;
		}
		bitPos++;
	}
	cout << answer;
}