#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> vec;

void recursion(vector<int> curr)
{
    if (curr.size() >= M)
    {
        for (int i = 0; i < curr.size(); i++)
            cout << curr[i] << " ";
        cout << "\n";
        return;
    }
    for (auto iter = find(vec.begin(), vec.end(), *(curr.end() - 1)); iter != vec.end(); iter++)
    {
        vector<int> tmp(curr);
        tmp.push_back(*iter);
        recursion(tmp);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        tmp.push_back(vec[i]);
        recursion(tmp);
    }
}