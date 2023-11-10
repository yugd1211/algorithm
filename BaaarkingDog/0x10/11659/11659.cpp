#include <iostream>
using namespace std;

int N, M;
int d[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> M;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        d[i] = d[i - 1] + num;
    }
    for (int i = 0; i < M; i++)
    {
        int start;
        int end;
        cin >> start;
        cin >> end;
        cout << d[end] - d[start - 1] << "\n";
    }
}