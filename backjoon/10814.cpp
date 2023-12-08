#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N;
map<int, vector<string>> mm;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age;
        cin >> name;
        mm[age].push_back(name);
    }
    for (int i = 1; i < 201; i++)
        for (int j = 0; j < mm[i].size(); j++)
            cout << i << " " << mm[i][j] << "\n";
}