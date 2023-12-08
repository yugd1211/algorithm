#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[1003];

// 4개까지의 갯수를 구해보니 값에 규칙성이 보였다.
// 해당 규칙성으로 예제에 주어지는 큰값을 구해보니 얼추 맞아서 그대로 풀어봄
// 홀수개 일때는 이전 갯수의 * 2 -1을 짝수개 일때는 * 2 +1를 한다.
// 나머지를 구해야하니 값을 구할때마다 % 10007을 해줬다.
// 이렇게하고 제출하니 99%에서 자꾸 틀리길래 뭐가 있을까 고민하다보니 n이 1개도 입력으로 주어진다.
// 이게 의미가 있나 했는데 1 x 2 직사각형이 하나 들어갈 수 있었다.
// 해당 값을 넣어주니 통과

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    for (int i = 4; i < 1002; i++)
    {
        if (i % 2)
            arr[i] = ((arr[i - 1] * 2) - 1) % 10007;
        else
            arr[i] = ((arr[i - 1] * 2) + 1) % 10007;
    }
    cout << arr[N];
}