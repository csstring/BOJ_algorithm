#include <iostream>
#include <string>
#include <iterator>
#include <deque>
#include <algorithm>
using namespace std;
deque<int> dp;
int n, val, find_val, max_size, temp;
size_t total, Index;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> max_size >> n;
  for (int i = 1; i < max_size + 1; ++i)
    dp.push_back(i);
  for (int i = 0; i < n; ++i)
  {
    cin >> find_val;
    Index = find(dp.begin(), dp.end(), find_val) - dp.begin();
    while (dp.front() != find_val)
    {
      if (dp.size() / 2 >= Index)
      {
        dp.push_back(dp.front());
        dp.pop_front();
      }
      else
      {
        dp.push_front(dp.back());
        dp.pop_back();
      }
      total++;
    }
    dp.pop_front();
  }
  cout << total;
}