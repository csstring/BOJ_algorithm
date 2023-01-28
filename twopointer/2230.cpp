#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,m,en,ans;
int b[100001];
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i =0; i <n; ++i) cin >> b[i];
  sort(b,b+n);
  ans = INT32_MAX;
  b[n] = ans;
  for (int st = 0; st <n && en <n; ++st)
  {
    while (en < n && b[en] - b[st] <m) en++;
    ans = min(ans, b[en]-b[st]);
  }
  cout << ans;
}