#include <iostream>
using namespace std;

int N;
int dist[15];

int main()
{
    cin >> N;

    dist[0] = 1;
    dist[1] = 1;
    dist[2] = 2;
    dist[3] = 4;
    for (int i = 4; i <= 11; i++)
        dist[i] = dist[i - 1] + dist[i - 2] + dist[i - 3];
    for (int j = 0; j < N; j++)
    {
        int n;
        cin >> n;
        cout << dist[n] << "\n";
    }
    return 0;
}
