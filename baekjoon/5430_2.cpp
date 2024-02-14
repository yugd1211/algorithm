#include <iostream>
#include <algorithm>
#include <sstream>
#include <deque>
using namespace std;

// 두번째 문제풀이
// 풀이자체는 이전과 다를바 없지만 이번에는 reverse함수를 실행시키는게 아니라
// 플래그를 줘서 front를 버릴지 back을 버릴지를 정하는 방식으로 바꿀 생각이다.
// 물론 출력도 플래그를 확인하고 front부터 출력할지 back부터 출력할지 정한다.

int N;

void pdq(deque<int> &dq, bool revFlag)
{
    cout << "[";
    if (!dq.empty())
    {
        if (!revFlag)
        {
            for (int i = 0; i < dq.size() - 1; i++)
                cout << dq[i] << ",";
            cout << dq[dq.size() - 1];
        }
        else
        {
            for (int i = dq.size() - 1; i > 0; i--)
                cout << dq[i] << ",";
            cout << dq[0];
        }
    }
    cout << "]\n";
}

void strToDq(deque<int> &dq, string &str, int n)
{
    stringstream ss;
    string tmp;

    str[0] = ',';
    str[str.size() - 1] = ',';
    ss.str(str);

    getline(ss, tmp, ',');
    while (n--)
    {
        getline(ss, tmp, ',');
        dq.push_back(stoi(tmp));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while (N--)
    {
        bool errFlag = false;
        bool revFlag = false;
        deque<int> dq;
        string fun, str;
        int n;
        cin >> fun >> n >> str;
        strToDq(dq, str, n);
        for (int i = 0; i < fun.size(); i++)
        {
            if (fun[i] == 'R')
                revFlag = !revFlag;
            else
            {
                if (dq.empty())
                {
                    errFlag = true;
                    break;
                }
                if (!revFlag)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        if (errFlag)
            cout << "error\n";
        else
            pdq(dq, revFlag);
    }
}