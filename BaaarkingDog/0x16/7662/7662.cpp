#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int T;

int main()
{
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int k;
        multiset<int> mSet;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            char c;
            int n;
            cin >> c;
            cin >> n;
            if (c == 'I')
                mSet.insert(n);
            else
            {
                if (mSet.size())
                {
                    if (n > 0)
                        mSet.erase(--mSet.end());
                    else
                        mSet.erase(mSet.begin());
                }
            }
        }
        if (mSet.size())
        {
            cout << *(--mSet.end()) << " " << *mSet.begin() << "\n";
        }
        else
            cout << "EMPTY"
                 << "\n";
    }
    return 0;
}