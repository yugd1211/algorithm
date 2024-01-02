#include <iostream>
#include <algorithm>
#include <stack>
#define X first
#define Y second
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    while (1)
    {
        int n;
        long long ans = 0;
        stack<pair<long long, long long>> stk;
        cin >> n;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            int hight;
            cin >> hight;
            int idx = i;
            // hight랑 stk.top이랑 "=" 일떄도 하는 이유는
            // 같은 크기의 노드가 여러개 있어도 처음 시작점을 저장하기 때문에
            // 중간의 노드들도 연산할 필요가없기 때문에 지워주기 위함이다.
            while (!stk.empty() && hight <= stk.top().X)
            {
                ans = max(ans, (i - stk.top().Y) * stk.top().X);
                idx = stk.top().Y;
                stk.pop();
            }
            stk.push({hight, idx});
        }
        while (!stk.empty())
        {
            ans = max(ans, (n - stk.top().Y) * stk.top().X);
            stk.pop();
        }
        cout << ans << "\n";
    }
}