#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long ticket[3];
long long gom[3];
long long val;

// 아래에는 틀린 코드가 있다.
// 이전 코드에서 틀린 부분을 찾지 못해서 다시 풀어봤다.
// 이전 코드는 하드코딩으로 티켓만큼 먹이고 나눴는데
// 이런 부분들을 반복문으로 바꿔가며 코드를 작성했다.
// 그렇게 같은 로직으로 코드를 작성하고 테스트해보니 결과가 달랐다.
// 확인해보니 티켓을 바꾸는 순서가 바뀌어서 결과가 달랐는데 여기서 틀린 이유를 인지했다.
// 이유는 각 티켓당 한번씩 총 3번의 교환이 이루어졌는데,
// 이럴경우 마지막에 교환한 티켓이 3개 이상이고 첫번째로 교환한 티켓으로 먹을 수 있는 곰곰이가 있는 경우에도 교환이 이루어지지 않고 끝난다.
// 그래서 마지막에도 한번 더 교환하게 반복문을 수정해서 통과했다.

int main()
{
	for (int i = 0; i < 3; i++)
		cin >> gom[i];
	for (int i = 0; i < 3; i++)
		cin >> ticket[i];
	for (int i = 0; i < 3; i++)
	{
		int m = min(ticket[i], gom[i]);
		val += m;
		ticket[i] -= m;
		gom[i] -= m;
	}
	for (int i = 0; i < 4; i++)
	{
		int prev = (i + 2) % 3;
		ticket[i % 3] += ticket[prev] / 3;
		ticket[prev] %= 3;
		int m = min(ticket[i % 3], gom[i % 3]);
		val += m;
		ticket[i % 3] -= m;
		gom[i % 3] -= m;
	}

	cout << val;
}




//long long  A, B, C; // 먹고싶은 수
//long long  X, Y, Z; // 식권 수
//long long val;

//int main()
//{
//	cin >> A >> B >> C;
//	cin >> X >> Y >> Z;
//	long long  eatChicken = min(A, X);
//	long long  eatPizza = min(B, Y);
//	long long  eatBurger = min(C, Z);
	
//	A -= eatChicken;
//	X -= eatChicken;
//	B -= eatPizza;
//	Y -= eatPizza;
//	C -= eatBurger;
//	Z -= eatBurger;
	
//	val = eatChicken + eatPizza + eatBurger;
//	// 기존의 식권으로 먹고싶어하는 곰곰이들을 일단 먹임

//	Y += X / 3;
//	X = X % 3;
//	eatPizza = min(B, Y);
//	B -= eatPizza;
//	Y -= eatPizza;
//	val += eatPizza;

//	Z += Y / 3;
//	Y = Y % 3;
//	eatBurger = min(C, Z);
//	C -= eatBurger;
//	Z -= eatBurger;
//	val += eatBurger;

//	X += Z / 3;
//	Z = Z % 3;
//	eatChicken = min(A, X);
//	A -= eatChicken;
//	X -= eatChicken;
//	val += eatChicken;

//	// 남은 식권은 바꿀수 있는 식권으로 바꿔가면서 곰곰이들을 먹임

//	cout << val;
//	return 0;
//}

