// 기본 구조는 똑같다 for문을 사용해서 더 편하게 코드를 작성
// 하면서 자꾸 bus error가 발생해서 문제가 있었다.
// dist의 크기를 100002으로 했는데 200002으로 하니까 에러가 통과됐었다.
// 그리고 다시보니 if문에서 배열넘어를 확인할 수 있는 부분이 있었다.
// 정적배열 선언할때 해당 부분 잘 체크해야겠다.


#include <iostream>
#include <queue>
#define num first
#define cnt second

int dist[100002];
int N, K;
using namespace std;
int main()
{
    queue<int> Q;
    cin >> N;
    cin >> K;
    Q.push(N);
    dist[N] = 0;
	int idx = 0;
    while (1)
    {
        int curr = Q.front();
        Q.pop();
		if (curr == K)
			break;
		for (int i = 0; i < 3; i++)
		{
			int next;
        	if (curr < 0 || curr > 100001) continue;
			if (i == 0)
				next = curr + 1;
			else if (i == 1)
				next = curr - 1;
			else if (i == 2)
				next = curr * 2;
			if (next >= 100001 ||dist[next] != 0) continue;
			dist[next] = dist[curr] + 1; 
			Q.push(next);
		}
    }
	cout << dist[K];
    return 0;
}