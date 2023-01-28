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
vector<int> v;
int t,n,val;
size_t ans;
int ft_gcd(int a, int b)
{
  if (a == 0) return b;
  return ft_gcd(b%a, a);
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> n;
    v.clear();
    ans = 0;
    for (int i =0; i <n; ++i){
      cin >> val;
      v.push_back(val);
    }
    for (int i = 0; i <v.size()-1; ++i)
      for (int j = i+ 1; j < v.size(); ++j)
        ans += ft_gcd(v[i],v[j]);
    cout << ans << '\n';
  }
}