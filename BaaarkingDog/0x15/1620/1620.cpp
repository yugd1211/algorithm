#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<string, int> nameLog;
string numLog[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> numLog[i];
        nameLog[numLog[i]] = i;
    }
    for (int i = 0; i < M; i++)
    {
        string query;
        cin >> query;
        if (isdigit(query[0]))
            cout << numLog[stoi(query)] << "\n";
        else
            cout << nameLog[query] << "\n";
    }
}