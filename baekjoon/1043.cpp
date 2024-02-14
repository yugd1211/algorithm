#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 문제풀이
// 간단하게 말하면 진실을 모르는 이들끼리 참가하는 파티를 모으면 된다.
// 중요한점은 원래는 진실을 몰랐어도 진실을 아는 이들과 파티를 함께하면 이들도 진실을 알게 된다는것이다.
// 그렇기 때문에 해당 인원들도 진실을 아는사람으로 취급해야한다.
// 그렇게 진실을 아는 사람들을 모두 업데이트 하면 모든 파티에서 해당 인원들이 있는지 없는 지 확인하면된다.
// 그러면 여기서 중요한것은 진실을 몰랐는데 진실을 아는 사람들과 파티해서 진실을 알게된 사람들을 찾아야한다.
// 모든 파티를 순회하며 파티에 참여한 인원들을 서로 가리키는 간선의 그래프를 만든다.
// 이떄 진실을 아는 사람과 파티하는 사람들은 진실을 아는 사람이 가리키는 간선에 추가된다.
// 그리고 처음 진실을 아는 사람들을 기준으로 bfs를 실행하게된다.
// 그럼 해당 사람이 참여한 모든 파티에서 만나는 사람들을 알 수 있기 때문에 해당 인원들에게 진실을 전파한다.
// bfs로 전파당한 사람과 파티를 하는 이들에게도 진실을 계속 전파하게 된다.

int N, M, T;

int tm[51];
vector<int> lst[51];
vector<vector<int>> party;

void shareTruth()
{
    for (int i = 1; i <= N; i++)
    {
        if (!tm[i])
            continue;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < lst[curr].size(); i++)
            {
                int nxt = lst[curr][i];
                if (tm[nxt])
                    continue;
                tm[nxt] = 1;
                q.push(nxt);
            }
        }
    }
}

bool isTruthMan(vector<int> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        int curr = p[i];
        if (tm[curr])
            return 1;
    }
    return 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N >> M >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        tm[n] = 1;
    }
    for (int i = 0; i < M; i++)
    {
        vector<int> vec;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        party.push_back(vec);
        for (int i = 0; i < vec.size(); i++)
        {
            int curr = vec[i];
            for (int j = 0; j < vec.size(); j++)
            {
                int nxt = vec[j];
                if (curr == nxt)
                    continue;
                lst[curr].push_back(nxt);
            }
        }
    }
    shareTruth();
    int ans = 0;
    for (int i = 0; i < party.size(); i++)
    {
        if (!isTruthMan(party[i]))
            ans++;
    }
    cout << ans;
}