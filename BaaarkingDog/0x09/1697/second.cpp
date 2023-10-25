#include <iostream>
#include <queue>
#define num first
#define cnt second


int dist[100002];
int N, K;
using namespace std;
int main()
{
    queue<int> Q;
    cin >> N;
    cin >> K;
    Q.push(N);
    dist[0] = 0;
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        if (curr < 0) continue;
        if (curr < 100000 && curr < K)
        {
            Q.push(curr + 1);
            dist[curr + 1] = dist[curr] + 1;
            if (dist[curr + 1] == K)
            {
                cout << dist[curr];
                return 0;
            }
        }
        Q.push(curr - 1);
        dist[curr - 1] = dist[curr] + 1;
        if (dist[curr - 1] == K)
        {
            cout << dist[curr];
            return 0;
        }
        if (curr < 50001 && curr < K)
        {

            Q.push(curr * 2);
            dist[curr * 2] = dist[curr] + 1;
            if (dist[curr * 2] == K)
            {
                cout << dist[curr];
                return 0;
            }
        }
    }
    return 0;
}