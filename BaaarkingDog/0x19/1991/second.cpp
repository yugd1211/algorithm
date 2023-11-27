#include <iostream>
#include <algorithm>

using namespace std;
int N;

// 127 대신 27개의 배열만을 선언하는 방식으로 변경
int parent[27];
int lc[27];
int rc[27];

void PreorderTraversal(int curr)
{
    if (curr <= 0 || curr == '.')
        return;
    cout << static_cast<char>(parent[curr] + 'A' - 1);
    PreorderTraversal(lc[curr]);
    PreorderTraversal(rc[curr]);
}

void InorderTraversal(int curr)
{
    if (curr <= 0 || curr == '.')
        return;
    InorderTraversal(lc[curr]);
    cout << static_cast<char>(parent[curr] + 'A' - 1);
    InorderTraversal(rc[curr]);
}

void PostorderTraversal(int curr)
{
    if (curr <= 0 || curr == '.')
        return;
    PostorderTraversal(lc[curr]);
    PostorderTraversal(rc[curr]);
    cout << static_cast<char>(parent[curr] + 'A' - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char p;
        char l;
        char r;
        cin >> p;
        cin >> l;
        cin >> r;
        p = p - 'A' + 1;
        l = l - 'A' + 1;
        r = r - 'A' + 1;
        parent[p] = p;
        lc[p] = l;
        rc[p] = r;
    }
    PreorderTraversal(1);
    cout << "\n";
    InorderTraversal(1);
    cout << "\n";
    PostorderTraversal(1);
}