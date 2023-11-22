#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

int N;

int main()
{
    map<string, bool> log;
    unordered_set<string> s;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string name;
        string behavior;
        cin >> name;
        cin >> behavior;
        if (behavior == "enter")
            log.insert({name, true});
        else
            log.erase(name);
    }
    for (map<string, bool>::iterator iter = --log.end(); iter != log.begin(); iter--)
        cout << iter->first << "\n";
    cout << log.begin()->first << "\n";
    return 0;
}