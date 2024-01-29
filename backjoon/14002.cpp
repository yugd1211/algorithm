#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;

int A[1001];
int DP[1001];
int prv[1001];

int main()
{
    cin >> N;
    for (int i = 0; i < 1001; i++)
        prv[i] = -1;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int curr = 0; curr < N; curr++)
    {
        for (int j = 0; j < curr; j++)
        {
            if (A[j] < A[curr])
            {
                if (DP[curr] >= DP[j] + 1)
                    continue;
                DP[curr] = DP[j] + 1;
                prv[curr] = j;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (DP[ans] < DP[i])
            ans = i;
    }
    cout << DP[ans] + 1 << "\n";
    stack<int> stk;
    while (ans >= 0)
    {
        stk.push(A[ans]);
        ans = prv[ans];
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}