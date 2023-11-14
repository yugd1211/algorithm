#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 틀린 방식 
// 그리드로 풀려고 함
// 현재 모든 휴게소들을 정렬하고 제일 거리가 먼거리의 중간에 휴게소를 짓는 방식

int N;
int M;
int L;
vector<int> rest;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    cin >> L;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        rest.push_back(num);
    }
    rest.push_back(L);
    rest.push_back(0);
    sort(rest.begin(), rest.end());
    cout << "==========start=================\n";
    cout << "================================\n";
    for (int i = 0; i < rest.size(); i++)
        cout << rest[i] << "\n";
    cout << "=============insert==============\n";
    cout << "================================\n";
    cout << "================================\n";
    for (int restCnt = 0; restCnt < M; restCnt++)
    {
        pair<int, int> minPlace;
        for (int i = 0; i < rest.size(); i++)
        {
            if (rest[i + 1] - rest[i] > minPlace.second)
            {
                minPlace.first = i;
                minPlace.second = rest[i + 1] - rest[i];
            }
        }
        cout << (rest[minPlace.first] + rest[minPlace.first + 1]) / 2 << "\n";
        rest.insert(rest.begin() + minPlace.first + 1, (rest[minPlace.first] + rest[minPlace.first + 1]) / 2);
    }
    int ans = 0;
    cout << "================end=============\n";
    cout << "================================\n";
    cout << "================================\n";
    for (int i = 0; i < rest.size(); i++)
    {
        cout << rest[i] << "\n";
        if (rest[i + 1] - rest[i] > ans)
        {
            ans = rest[i + 1] - rest[i];
        }
    }
    cout << ans;
    return 0;
}