#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제풀이
// N마다 모든 간선을 그리는 그래프를 그리려고했는데 그렇게하니
// 100000 * 1000 * 1000 만큼의 메모리가 필요해서 메모리초과
// 그래서 아예 백지부터 다시시작
// 2개의 그래프를 그리면 어떨까
// 하이퍼튜브를 정점으로 두고 각 역을 간선으로 두는 그래프를 두는것
// 그러면 1000 * 1000의 그래프가 하나 완성된다.
// 몇번 하이퍼튜브에 어떤 역들이 들어가있는지가 담기는것
// 그리고 그래프를 하나더 만들어야한다.
// 각 역별로 어떤 하이퍼튜브를 탈 수 있는지에 대한 그래프
// 이 그래프는 100000 + 1000 * 1000의 그래프가 완성된다.

// 주의할점
// station에 대한 vis는 체크했는데 hyperTube의 방문체크를 하지 않으니까 무한으로 즐겨버리는 상황이 발생했었다.
// station과 hyperTube 둘다 방문확인을 해줘야한다.

vector<int> hyperTube[1001];
vector<int> station[100001];
int stationVis[100001];
int hyperVis[100001];

int N, K, M;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    queue<int> q;
    cin >> N >> K >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int n;
            cin >> n;
            hyperTube[i].push_back(n);
            station[n].push_back(i);
        }
    }
    stationVis[1] = 1;
    q.push(1);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < station[curr].size(); i++)
        {
            int currHyper = station[curr][i];
            if (hyperVis[currHyper])
                continue;
            hyperVis[currHyper] = 1;
            for (int j = 0; j < hyperTube[currHyper].size(); j++)
            {
                int nxt = hyperTube[currHyper][j];
                if (stationVis[nxt])
                    continue;
                stationVis[nxt] = stationVis[curr] + 1;
                q.push(nxt);
            }
        }
    }
    if (stationVis[N])
        cout << stationVis[N];
    else
        cout << "-1";
}
