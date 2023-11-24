#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N;
long long total;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> N;
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        pq.push(n);
    }
    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        pq.push(first + second);
        total += first + second;
    }
    cout << total << "\n";
}