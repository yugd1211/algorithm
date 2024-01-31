#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lc[100001];
int rc[100001];
int N;
long long ans;

void inorder(int parent)
{
    if (parent == -1)
        return;
    cout << "parent = " << parent << ", lc = " << lc[parent] << ", rc = " << rc[parent] << '\n';
    inorder(lc[parent]);
    inorder(rc[parent]);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        lc[a] = b;
        rc[a] = c;
    }
    inorder(1);
    cout << ans;
}