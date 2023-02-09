#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
using namespace std;
int b[2000];
set<int> s;
int n,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i) cin >> b[i];
  sort(b,b+n);
  for (int i =0; i <n-1; ++i)
  {
    for (int j =i+1; j <n; ++j)
    {
      int ddx = lower_bound(b, b+n,b[i]+b[j]) -b;
      int udx = upper_bound(b, b+n,b[i]+b[j]) -b;
      if (ddx == n ) continue;
      if (ddx == i || ddx == j) continue;
      if (s.insert(b[i] +b[j]).second == false) continue;
      ans += udx - ddx;
    }
  }
  cout << ans;
}