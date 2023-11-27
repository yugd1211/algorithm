#include <iostream>
#include <algorithm>

using namespace std;
int N;

// 메모리 초과

int parent[127];
int lc[127];
int rc[127];

void PreorderTraversal(int curr)
{
    if (curr == 0)
        return;
    cout << static_cast<char>(parent[curr]);
    PreorderTraversal(lc[curr]);
    PreorderTraversal(rc[curr]);
}

void InorderTraversal(int curr)
{
    if (curr == 0)
        return;
    InorderTraversal(lc[curr]);
    cout << static_cast<char>(parent[curr]);
    InorderTraversal(rc[curr]);
}

void PostorderTraversal(int curr)
{
    if (curr == 0 && curr == '.')
        return;
    PostorderTraversal(lc[curr]);
    PostorderTraversal(rc[curr]);
    cout << static_cast<char>(parent[curr]);
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
        parent[p] = p;
        lc[p] = l;
        rc[p] = r;
    }
    PreorderTraversal('A');
    cout << "\n";
    InorderTraversal('A');
    cout << "\n";
    PostorderTraversal('A');
}