#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int k,n;
int b[10000];
bool solve(size_t mid)
{
  size_t ans = 0;
  for (int i =0; i <k; ++i) ans += b[i] / mid;
  return ans >= n;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> n;
  for (int i =0; i <k; ++i) cin >> b[i];
  size_t st = 1;
  size_t en = INT32_MAX;
  while (st < en)
  {
    size_t mid = (st + en + 1)/2;
    if (solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}