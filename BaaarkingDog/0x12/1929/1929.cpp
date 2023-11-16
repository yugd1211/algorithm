#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;

vector<int> sieve(int num)
{
    vector<int> primes;
    vector<bool> state(num + 2, true);

    for (int i = 2; i * i <= num; i++)
    {
        if (!state[i]) 
            continue;
        for (int j = i * i; j <= num; j += i)
            state[j] = false;
    }
    for (int i = 2; i <= num; i++)
        if (state[i])   primes.push_back(i);
    return primes;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M;
    cin >> N;
    vector<int> vec;
    vec = sieve(N);

    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        if (*iter < M) continue;
        cout << *iter << "\n";
    }
    return 0;
}