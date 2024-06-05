#include <iostream>
#include <vector>
#include <string>
using namespace std;

int g_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int g_days[366];

// 예외처리
// 11.30까지 꽃이 펴있어야되기 때문에 30일에 꽃이 지는게 아니라 31일에 꽃이 져야 했다. 문제를 잘 읽어야한다....
// 그 외에는 큰 예외처리는 딱히 없었다.

// 풀이법
// 꽤 간단하다. 1월 1일부터 12월 31일까지 365일에 대해서 제일 최대길이까지 피는 꽃만 남겨놓는다.
// 해당 꽃들을 확인하기만 하면된다. 확인하는 과정의 시간복잡도는 n(2) 일 수 있지만 n을 100000에서 365로 줄여버렸기 때문에 괜찮다.
// 그외에 아이디어중 하나는 월일을 따로 나누면 확인하는 과정이 귀찮기 때문에 365일기준으로 바꿔서 처리했다.

int N; // 100000 이하

int DaysCal(int month, int day)
{
	int res = 0;
	for (int i = 0; i < month - 1; i++)
	{
		res += g_month[i];
	}
	res += day;
	return res;
}

void ReversDaysCal(int days, int &month, int &day)
{
	for (int i = 0; i < 12; i++)
	{
		month = i + 1;
		if (days < g_month[i] + 1)
			break;
		days -= g_month[i];
	}
	day = days;
}

int PickFlower(int month, int day)
{
	int days = DaysCal(month, day);
	int res = -1;
	for (int i = days; i > 0; i--)
	{
		if (g_days[i] == 0)
			continue;
		if (res == -1 || g_days[i] > g_days[res])
			res = i;
	}
	return res;
}

void DisplayDays(int days)
{
	int m, d;
	ReversDaysCal(days, m, d);
	cout << "월 = " << m << ", 일 = " << d << "\n";
}

int main()
{
	std::cin.tie(0);
	std::ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int aMonth;
		int aDay;
		int bMonth;
		int bDay;
		cin >> aMonth;
		cin >> aDay;
		cin >> bMonth;
		cin >> bDay;
		int start = DaysCal(aMonth, aDay);
		int end = DaysCal(bMonth, bDay);
		if (!g_days[start] || g_days[start] < end)
			g_days[start] = end;
	}
	int start, next;
	int res = 0;
	while (1)
	{
		if (!res)
		{
			start = PickFlower(3, 1);
			next = g_days[start];
		}
		else
		{
			start = next;
			int a, b;
			ReversDaysCal(start, a, b);
			next = g_days[PickFlower(a, b)];
		}
		res++;
		if (start >= next)
		{
			res = 0;
			break;
		}
		if (next >= DaysCal(11, 31))
			break;
	}
	cout << res;
}