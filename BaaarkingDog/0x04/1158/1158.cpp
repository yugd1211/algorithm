#include <iostream>
#include <queue>


using namespace std;
int main()
{
    int N;
    int K;
    std::queue<int> Q; 
    cin >> N;
    cin >> K;
    for (int i = 1; i <= N; i++)
        Q.push(i);
    std::cout << "<";
    while (!Q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            Q.push(Q.front());
            Q.pop();
        }
        std::cout << Q.front();
        Q.pop();
        std::cout << ", ";
    }
    std::cout << ">\n";
}

