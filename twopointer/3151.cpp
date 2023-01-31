#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int b[4000];
ssize_t n,ans;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<n; ++i) cin >> b[i];
  sort(b,b+n);
  for (int i =0; i <n-3;++i)
  {
    for (int j = i+1; j <n-2; ++j)
    {
      auto st = lower_bound(b+j+1, b+n, -b[i]-b[j]);
      auto en = upper_bound(b+j+1, b+n, -b[i]-b[j]);
      ans += en-st;
    }
  }
  cout << ans;
}