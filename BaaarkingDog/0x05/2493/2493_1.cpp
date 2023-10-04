#include <iostream>
#include <stack>
#include <algorithm>

/*
*   혼자 풀어본 코드
*   크게 생각하지 않고 모든 수를 스택에 쌓아두고 맨 오른쪽부터 확인
*   스택을 다 빼가면서 작은 수들을 임시 스택에 쌓아뒀다가 다시 원상복귀
*   자신보다 큰수를 찾으면 해당 출력용 스택에 쌓음
*   임시 스택에 쌓아뒀던 수들을 다시 수열을 담는 스택에 쌓음
*   이러한 방식으로 진행하니 타임아웃 발생
*/

using namespace std;
int main()
{
    int N = 0;
    int pos;
    std::stack<int> stk;
    std::stack<int> ret;

    cin >> N;
    pos = N;
    for (int i = 0; i < N; i++)
    {
        int num = 0;
        cin >> num;
        stk.push(num);
    }
    for (int i = 0; i < N; i++)
    {
        int curr = stk.top();
        stk.pop();
        pos--;
        std::stack<int> tmp;
        while (1)
        {
            if (stk.empty())
            {
                ret.push(0);
                break;
            }
            int leftTop = stk.top();
            if (leftTop > curr)
            {
                ret.push(pos);
                break;
            }
            else
            {
                tmp.push(leftTop);
                stk.pop();
                pos--;
            }
        }
        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
            pos++;
        }
    }
    while (!ret.empty())
    {
        std::cout << ret.top() << " ";
        ret.pop();
    }
}