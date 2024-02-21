#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제풀이
// 두개의 우선순위큐를 사용하는 방법이 떠오름
// 오름차순 정렬 큐와 내림차순 정렬 큐를 사용해서
// 먼저 값이들어오면 오름차순 큐에 저장을하고 해당 큐와 내림차순 큐의 size가 2개이상일때 값을 옮겨주는 작업이 일어난다.
// 출력은 오름차순 큐의 top을 출력한다.
// 항상 오름차순큐가 내림차순 큐보다 커야한다.
// 두 큐의 size의 합이 홀수일떄는 오름차순 큐가 1개 더 많아야 하고
// 짝수일때는 오른차순 큐가 2개 더 많아야한다.

int N;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
}