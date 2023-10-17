#include <iostream>
#include <stack>

using namespace std;

// 스택에서 어려운 점은 앞에서 부터 시작할지 뒤에서 부터 시작할지
// 카운트를 누구를 기준으로 샐지를 정하는게 어려운것 같다.
// 이전의 문제들은 스택을 쌓고 해당 size를 더해주는 문제들이 많았는데
// 이번 문제는 스택에서 나보다 작은 애들을 빼면서 return 값을 더해줘야 했다.
// 이런 생김새가 처음이라 다른 해설들을 봐도 이해가 잘안되었다.
// 풀이는 위에 설명한것처럼 스택의 Top과 curr을 비교하며 작은 수들은 pop하고 ret값을 증가한다.
// 같은 값에 대한 처리는 일단 생각도 못하고 있었지만, 해설들을 보니
// 같은 값들에 대한 처리를 위해 pair를 사용해서 second에 몇중첩인지를 올려주는 식으로 풀이를 했다.
// 큰값들은 생각할것 없이 ret 값을 올리고 스택에 push한다

int main()
{
    int num = 0;
    std::stack<std::pair<int, int> > stk;
    long long ret = 0;
    cin >> num;
    
    for (int i = 0; i < num; i++)
    {
        int curr = 0;
        int overlap = 1;
        cin >> curr;
        while (!stk.empty() && stk.top().first < curr)
        {
            ret += stk.top().second;
            stk.pop();
        }
        if (!stk.empty())
        {
            if (stk.top().first == curr)
            {
                overlap = stk.top().second;
                ret += overlap++;
                stk.pop();
            }
            if (!stk.empty()) ++ret;
        }
        stk.push(make_pair(curr, overlap));
    }
    cout << ret;
    return 0;
}
