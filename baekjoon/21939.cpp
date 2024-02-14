#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// recommend 1 = 가장 어려운 문제
// recommend -1 = 가장 쉬운 문제
// 여러개라면 문제 번호가 작은것 출력

// add P L = 난이도가 L인 문제 번호 P를 추가
// solved P = P 번 문제를 제거

// 입력
// N : 문제 개수
// P L : 문제번호, 난이도
// M : 명령어
// 명령문

// recommend 출력

int N, M;
int prob[100001];
// 난이도, 번호
multiset<pair<int, int>> ms;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int p, l;
        cin >> p >> l;
        ms.insert({l, p});
        prob[p] = l;
    }
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string c;
        int n;
        cin >> c >> n;
        if (c == "recommend")
        {
            if (n == 1)
                cout << (--ms.end())->second << "\n";
            else
                cout << ms.begin()->second << "\n";
        }
        else if (c == "solved")
        {
            ms.erase(ms.find({prob[n], n}));
        }
        else
        {
            int l;
            cin >> l;
            ms.insert({l, n});
            prob[n] = l;
        }
    }
}