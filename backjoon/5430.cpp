#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// 첫번째 문제 풀이
// 문제에서 주는대로 R는 reverse함수를 사용하고 D는 pop_pront를 실행했다.
// 결과는 시간초과 문제 풀이자체는 틀리지 않았지만 연산이 너무 오래걸리는것 같다.
// reverse가 문제일거 같아서 RR의 경우 원상태로 돌아오니 이럴경우는 건너띄었지만 그래도 시간초과
// 아직도 reverse가 문제일거같아서 로직 자체를 바꾸기고 결정함

int N;

void reverseDq(deque<int> &dq)
{
    reverse(dq.begin(), dq.end());
}

void printDq(deque<int> &dq)
{
    cout << "[";
    if (!dq.empty())
    {
        for (int i = 0; i < dq.size() - 1; i++)
            cout << dq[i] << ",";
        cout << dq.back();
    }
    cout << "]\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    while (N--)
    {
        string fun, str;
        bool err = false;
        deque<int> dq;
        int len;
        cin >> fun >> len >> str;
        for (int i = 0; i < len; i++)
            dq.push_back(str[(i * 2) + 1] - '0');
        for (int i = 0; i < fun.size(); i++)
        {
            if (fun[i] == 'R' && fun[i + 1] == 'R')
                i++;
            else if (fun[i] == 'R')
                reverseDq(dq);
            else
            {
                if (dq.empty())
                {
                    err = true;
                    break;
                }
                else
                    dq.pop_front();
            }
        }
        if (err)
            cout << "error\n";
        else
            printDq(dq);
    }
}