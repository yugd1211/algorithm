#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// age의 최대 크기가 작기 때문에 map이 아니여도 됐다.
// for문 자체도 map을 활용해서 사용하질 않았음 :(

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