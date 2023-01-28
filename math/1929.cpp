#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<bool> v(1000002,true);
void sieve(int k)
{
  v[1] = false;
  for (int i = 1; i*i <=k ;++i)
  {
    if (!v[i]) continue;
    for (int j = i*i; j <=k; j += i)
      v[j] = false;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> m >>n;
  sieve(n);
  for (int i =m; i <=n; ++i)
  {
    if (v[i]) cout << i << '\n';
  }
}