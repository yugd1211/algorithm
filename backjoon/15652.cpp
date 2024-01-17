#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

void recursion(vector<int> vec)
{
    if (vec.size() == M)
    {
        for (int i = 0; i < M; i++)
            cout << vec[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = *(vec.end() - 1); i <= N; i++)
    {
        vector<int> tmp(vec);
        tmp.push_back(i);
        recursion(tmp);
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        vector<int> vec;
        vec.push_back(i);
        recursion(vec);
    }
}