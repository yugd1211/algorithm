#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int adj[27][2];

void preorder(int p)
{
    if (p == 0)
        return;
    cout << char(p + 'A' - 1);
    preorder(adj[p][0]);
    preorder(adj[p][1]);
}
void inorder(int p)
{
    if (p == 0)
        return;
    inorder(adj[p][0]);
    cout << char(p + 'A' - 1);
    inorder(adj[p][1]);
}
void postorder(int p)
{
    if (p == 0)
        return;
    postorder(adj[p][0]);
    postorder(adj[p][1]);
    cout << char(p + 'A' - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char p, lc, rc;
        cin >> p >> lc >> rc;
        if (lc != '.')
            adj[p - 'A' + 1][0] = lc - 'A' + 1;
        if (rc != '.')
            adj[p - 'A' + 1][1] = rc - 'A' + 1;
    }
    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
}