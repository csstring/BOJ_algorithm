#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,ans,en,cur;
int b[4000003];
vector<bool> v(4000003, false);
void sieve()
{
  v[1] = true;
  for (int i=2; i *i <=n; ++i)
  {
    for (int j = i*i; j <=n; j += i)
    {
      v[j] = true;
    }
  }
}
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  sieve();
  int tmp = 0;
  for (int i =1; i <=n; ++i){
    if (v[i]) continue;
    b[tmp++] = i;
  }
  for (int st = 0;st < tmp; ++st)
  {
    while (en <= tmp && cur < n)
    {
      cur += b[en++];
    }
    if (en == tmp+1) break;
    if (cur == n) ans++;
    cur -= b[st];
  }
  cout << ans;
}