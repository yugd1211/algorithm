#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> nums;
	vector<char> opers;
	string input;
	cin >> input;
	stringstream ss(input);

	while (ss)
	{
		int num;
		char oper;
		if (ss >> num)
		{
			nums.push_back(num);
		}
		if (ss >> oper)
		{
			if (oper == '+' || oper == '-')
				opers.push_back(oper);
		}
	}
	int answer = 0;
	while (find(opers.begin(), opers.end(), '+') != opers.end())
	{
		int pos = find(opers.begin(), opers.end(), '+') - opers.begin();
		nums[pos] += nums[pos + 1];
		nums.erase(nums.begin() + pos + 1);
		opers.erase(opers.begin() + pos);
	}
	answer = nums[0];
	for (int i = 1; i < nums.size(); i++)
		answer -= nums[i];
	cout << answer;
}