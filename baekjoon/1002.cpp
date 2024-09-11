#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int T;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		int cmp1 = pow(r1 - r2, 2);
		int cmp2 = pow(r1 + r2, 2);

		if (d == 0)
		{
			if (cmp1 == 0)
				std::cout << -1 << "\n";
			else
				std::cout << 0 << "\n";
		}
		else if (d == cmp1 || d == cmp2)
			std::cout << 1 << "\n";
		else if (cmp1 < d && d < cmp2)
			std::cout << 2 << "\n";
		else
			std::cout << 0 << "\n";
	}

	return 0;
}