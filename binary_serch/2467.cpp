#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int m1,m2,n,val,ans;
vector<int> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i){
    cin >> val;
    v.push_back(val);
  }
  ans = INT32_MAX;
  for (int i=0; i< n; ++i)
  {
    auto it = lower_bound(v.begin(),v.end(),-1*v[i]);
    if (it == v.end()) it = prev(it);
    if (it != v.begin() && v[i] != *prev(it))
    {
      if (v[i] == *it) it = prev(it);
      else if (abs(v[i] + *prev(it))<abs(v[i] +*it))
        it = prev(it);
    }
    else if (it == v.begin() && v[i] == *it) it = next(it);
    if (abs(v[i] + *it) < abs(ans))
    {
      m1 = min(v[i], *it);
      m2 = max(v[i], *it);
      ans = m1+m2;
    }
  }
  cout << m1 << ' '<< m2;
}