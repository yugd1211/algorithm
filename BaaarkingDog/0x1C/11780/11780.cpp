#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int city[101][101];
int vis[101][101];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            if (i != j)
                city[i][j] = 1000000001;
    for (int i = 0; i < M; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        if (cost < city[a][b])
        {
            city[a][b] = cost;
            vis[a][b] = b;
        }
    }
    for (int so = 1; so <= N; so++)
    {
        for (int st = 1; st <= N; st++)
        {
            for (int en = 1; en <= N; en++)
            {
                if (city[st][so] + city[so][en] < city[st][en])
                {
                    // 주의 할점 so를 직접넣는게 아니라 so를 가기위한 경로를 저장하는것임
                    // vis[st][en] = so;
                    vis[st][en] = vis[st][so];
                    city[st][en] = city[st][so] + city[so][en];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (city[i][j] == 1000000001)
                cout << "0 ";
            else
                cout << city[i][j] << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int next = vis[i][j];
            if (next == 0)
            {
                cout << 0 << "\n";
                continue;
            }
            vector<int> route;
            route.push_back(i);
            while (1)
            {
                route.push_back(next);
                if (!vis[next][j])
                    break;
                next = vis[next][j];
            }
            cout << route.size() << " ";
            for (int i = 0; i < route.size(); i++)
                cout << route[i] << " ";
            cout << "\n";
        }
    }
}