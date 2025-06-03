#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int cnt = 0;
	long long X, K;
	cin >> X >> K;
	// 5
	// 101
	//  10
	// 1010
	//

	//    00101 : 5

	// 1. 00010 : 2

	// 2. 01000 : 8
	// 3. 01010 : 10

	// 4. 10000 : 16
	// 5. 10010 : 18
	// 6. 11000 : 24
	// 7. 11010 : 26

	// 8. 100000 : 32
	// 9. 100010 : 34
	// 10. 101000 : 40
	// 11. 101010 : 42
	// 12. 110000 : 48
	// 13. 110010 : 50
	// 14. 111000 : 56
	// 15. 111010 : 58

	long long ret = 1;
	while (cnt != K)
	{
		if (!(X & ret))
			cnt++;
		ret++;
	}
	cout << ret;
}