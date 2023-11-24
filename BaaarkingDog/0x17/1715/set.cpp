#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

int N;
long long total;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  multiset<int> s;
  cin >> N;
  int n;
  for (int i = 0; i < N; i++)
  {
    cin >> n;
    s.insert(n);
  }

  while (s.size() > 1)
  {
    int first = *s.begin();
    s.erase(s.begin());
    int second = *s.begin();
    s.erase(s.begin());
    s.insert(first + second);
    total += first + second;
  }
  cout << total << "\n";
}