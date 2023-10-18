#include <iostream>
#include <queue>

using namespace std;
int main()
{
    std::queue<int> Q;
    bool b = false;
    int num; cin >> num;
    for (int i = 1; i <= num; i++)
        Q.push(i);
    while (1)
    {
        if (Q.size() == 1)
        {
            std::cout << Q.front();
            return 0;
        }
        if (b)
            Q.push(Q.front());
        Q.pop();
        b = !b;
    }
}