#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

tuple<int, int, int> tl[100005];
vector<int> p(10005);
int V, E;
long long total;
int getParent(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = getParent(p[x]);
}

int unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return 0;
    p[a] = b;
    return 1;
}

// 아래의 코드는 실패함 왜그런 지모르겠음..
// bool checkParent(int a, int b)
// {
//     return getParent(a) == getParent(b);
// }

// int unionParent(int a, int b)
// {
//     if (checkParent(a, b))
//         return 0;
//     p[a] = b;
//     return 1;
// }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 1; i < V; i++)
        p[i] = i;
    for (int i = 0; i < E; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;
        tl[i] = {C, A, B};
    }
    sort(tl, tl + E);
    int cnt = 0;
    for (int i = 0; i < E; i++)
    {
        if (!unionParent(get<1>(tl[i]), get<2>(tl[i])))
            continue;
        total += get<0>(tl[i]);
        cnt++;
        if (cnt == V - 1)
            break;
    }
    cout << total;
}
