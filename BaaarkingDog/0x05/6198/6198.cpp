#include <iostream>
#include <stack>

/*
*   재귀같은 방법의 풀이 밖에 생각이 나지 않았다....
*   그래서 다른 사람의 코드를 확인했는데, 왜 그런 로직을 돌리는지가 이해가 되지 않았다.
*   블로그들을 찾아보니 다 똑같은 로직인데 왜 그렇게 하는지에 대한 설명은 없었는데 하나의 설명이 있었다.
*   나를 볼 수 있는 빌딩의 갯수를 새야한다.
*   내가 처음 생각이 든건 스택에 넣었다가 나보다 큰 빌딩이 나올때까지 카운트하고 다시 되돌리는 방법이였는데
*   아예 시점을 바꿔야 됐었다.
*   나를 볼 수 있는 빌딩의갯수를 새는건 간단하다. 나보다 낮은 애들은 모두 스택에서 빼면 된다
*/  


using namespace std;
int main()
{
    int N;
    long long ret = 0;
    stack<pair<int, int> > tower;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int H;
        cin >> H;
        while (!tower.empty() && tower.top().first <= H)
            tower.pop();
        ret += tower.size();
        tower.push(make_pair(H, i));
    }
    cout << ret;
}