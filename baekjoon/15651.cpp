#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

void Recursion(vector<int> vec, int curr)
{
    if (vec.size() >= M)
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        vector<int> tmp(vec);
        tmp.push_back(i);
        Recursion(tmp, i);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        vector<int> tmp;
        tmp.push_back(i);
        Recursion(tmp, i);
    }
}