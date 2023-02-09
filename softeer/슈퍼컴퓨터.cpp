#include <iostream>
#include <algorithm>
using namespace std;
ssize_t c;
size_t en = 1e18;
size_t st = 1;
int n;
int b[100000];
bool bserch(ssize_t mid)
{
  ssize_t ans = 0;
  for (int i =0; i<n; ++i)
  {
    if (b[i] >= mid) break;
    if (mid-b[i] >1e9) return false;
    ans += (mid-b[i]) * (mid-b[i]);
    if (ans <0 || ans > c) return false;
  }
  return true;
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>c;
  for (int i =0; i <n; ++i) cin >> b[i];
  sort(b,b+n);
  while (st < en)
  {
    ssize_t mid = (st +en +1)/2;
    if (bserch(mid)) st = mid;
    else en = mid-1;
  }
  cout << st;
} 