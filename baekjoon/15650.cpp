#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

void fun(int curr, vector<int> v)
{
    v.push_back(curr);
    if (v.size() == M)
    {
        for (int i = 0; i < M; i++)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = curr; i < N; i++)
    {
        if (v.size() > M)
            return;
        fun(i + 1, v);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        fun(i, vector<int>());
}
