#include <iostream>
#include <set>
#include <iterator>
using namespace std;
int Count, val, total;
set<int> s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int temp;
  cin >> Count;
  for (int i = 0; i < Count; ++i)
  {
    cin >> temp;
    s.emplace(temp);
  }
  cin >> val;
  for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
  {
    if (s.find(val - *it) != s.end())
      total++;
  }
  cout << total / 2;
}