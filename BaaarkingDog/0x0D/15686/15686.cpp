#include <iostream>
#include <cstdlib> 

using namespace std;

int chickenDistance(int home[2], int chicken[2])
{
    int a = abs(home[0] - chicken[0]);
    int b = abs(home[1] - chicken[1]);
    return a + b;
}
int main()
{
    int a[2] = {1, 2};
    int b[2] = {2, 1};
    cout << chickenDistance(a, b);
    return 0;
}
