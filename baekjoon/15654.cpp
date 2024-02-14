#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;

vector<int> vec;

void recursion(vector<int> curr)
{
    if (curr.size() == M)
    {
        for (int i = 0; i < curr.size(); i++)
            cout << curr[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        bool f = 0;
        for (int j = 0; j < curr.size(); j++)
        {
            if (curr[j] == vec[i])
            {
                f = 1;
                break;
            }
        }
        if (f)
            continue;
        vector<int> tmp(curr);
        tmp.push_back(vec[i]);
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
    for (int i = 0; i < vec.size(); i++)
    {
        vector<int> tmp;
        tmp.push_back(vec[i]);
        recursion(tmp);
    }
}