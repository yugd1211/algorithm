#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int N;

bool isPalindrome(int num)
{
	string str = to_string(num);
	auto front = str.begin();
	auto end = --str.end();
	while (front < end)
	{
		if (*front != *end)
			return false;
		front++;
		end--;
	}
	return true;
}

bool isPrime(int num)
{
	for (int i = 2; i < num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> N;
	if (N == 1)
	{
		cout << 2;
		return 0;
	}

	while (1)
	{
		if (isPalindrome(N) && isPrime(N))
		{
			cout << N;
			return 0;
		}
		N++;
	}
}