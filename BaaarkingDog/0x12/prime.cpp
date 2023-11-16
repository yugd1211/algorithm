#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << " is not prime number\n";
            return 0;
        }
    }
    cout << num << " is prime number\n";
    return 0;
}