#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 문제풀이
// 그래프를 사용해서 문제를 풀었다.
// 하나의 노드당 하나의 간선이 주어지기 때문에 n x n만큼의 배열을 생성하거나 리스트를 두지않고
// 그냥 하나의 노드만 담는 배열을 선언했다.
// 로직설명을 하자면 모든 노드 각각 dfs를 실행하는데 상태를 5개로 줬다.
// 해당 노드를 판별하기 위한 3개의 상태와 해당 노드가 어떻게 판단됐는지를 확인하기 위한 2개의 상태
// dfs에서 확인하고자 하는것은 순환그래프인지를 확인한다.
// 이를 위해서 3개의 상태가 필요한데 방문하지 않음, 방문 중, 방문 완료 3개의 상태로 확인한다.
// 먼저 모든 노드를 방문하지 않음으로 초기화하고, dfs를 실행할때 해당 노드를 방문하면 방문 중으로 바꾼다.
// 만약 이전에 방문했던(상태가 방문 중) 노드일 경우 방문 완료로 바꾸고 계속 실행한다.
// 그리고 방문 완료(사이클, 논사 이클도 있다)를 만날경우 해당 dfs는 종료된다.
// 그렇게 노드의 사이클 여부를 판단했으면 사이클인지 아닌지를 판정한다.
// 이제 노드의 상태는 방문중, 방문 완료 중 하나일 것이다(방문하지 않음은 있을 수 없다, dfs에서 이미 다 방문중으로 바꿧기 때문).
// 이때 방문 완료인 경우는 사이클 때문에 2번 방문했기 때문에 사이클이라 판단하고, 방문 중인 상태는 한번만 방문했기때문에 사이클이 아닐거라 판단하고, 사이클 - 논사이클로 상태를 변경한다.
// 그리고 다음 노드의 dfs를 실행할때 (사이클, 논 사이클인 노드는 이전에 이미 dfs를 실행한 노드이기때문에 종료하고 바로 사이클인지를 판정한다.)

enum e_state
{
    nonVisited,
    visiting,
    visited,
    nonCycle,
    cycle
};

int arr[100001];
int vis[100001];
int T;

void clearArr()
{
    for (int i = 0; i < 100001; i++)
    {
        arr[i] = 0;
        vis[i] = 0;
    }
}

void detectCycleDFS(int n)
{
    while (1)
    {
        if (vis[n] == visited || vis[n] == nonCycle || vis[n] == cycle)
            return;
        else if (vis[n] == nonVisited)
            vis[n] = visiting;
        else if (vis[n] == visiting)
            vis[n] = visited;
        n = arr[n];
    }
}

void isCyclic(int n)
{
    while (1)
    {
        if (vis[n] == cycle || vis[n] == nonCycle)
            return;
        else if (vis[n] == visiting)
            vis[n] = nonCycle;
        else if (vis[n] == visited)
            vis[n] = cycle;
        n = arr[n];
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        clearArr();
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        for (int i = 1; i <= n; i++)
        {
            detectCycleDFS(i);
            isCyclic(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i] == nonCycle)
                ans++;
        cout << ans << "\n";
    }
}