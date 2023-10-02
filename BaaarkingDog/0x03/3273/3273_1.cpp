#include <iostream>
#include <vector>

void getSequence(std::vector<int> &num, int N)
{
    int n;
    for (int i = 0; i < N; i++)
    {
        std::cin >> n;
        num.push_back(n);
    }
}

void getX(int &X)
{
    std::cin >> X;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N;
    int X;
    int numCheck[1000001] = {};
    std::cin >> N;
    std::vector<int> inputNum;
    getSequence(inputNum, N);
    getX(X);
    int ret = 0;
    for (int i = 1; i < N; i++)
    {
        if (X - inputNum[i] < 1000001)
            if (numCheck[X - inputNum[i]])
            {
                // std::cout << "X = " X << std::endl;
                // std::cout << " = " X << std::endl;
                // std::cout << "X = " X << std::endl;
                ret++;
            }
        numCheck[inputNum[i]] = 1;
    }
    std::cout << ret;
}