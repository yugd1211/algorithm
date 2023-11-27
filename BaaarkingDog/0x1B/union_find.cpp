#include <iostream>

using namespace std;
int getParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = getParent(parent, parent[x]);
    return parent[x];
}

int unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 0;
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
    return 1;
}

int findParent(int parent[], int a, int b)
{
    if (getParent(parent, a) == getParent(parent, b))
        return 1;
    return 0;
}

int main()
{
    int parent[11];
    for (int i = 1; i < 11; i++)
        parent[i] = i;
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);
    cout << "1, 5는 연결되어 있나? " << findParent(parent, 1, 5) << "\n";
}