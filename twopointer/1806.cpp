#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,s,st,en,ans;
int b[100001];
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >>n>>s;
  ans = INT32_MAX;
  for (int i =1; i <=n; ++i) cin >> b[i];
  st =1; en =1;
  int cur = b[1];
  while (en <= n)
  {
    if (cur >= s)
    {
      ans = min(ans, en - st+1);
      if (ans == 1) break;
      cur -= b[st];
      st++;
    }
    else{
      en++;
      cur += b[en];
    }
  }
  if (ans == INT32_MAX) ans = 0;
  cout << ans;
}