#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int t,n,m;
vector<int> a,b;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--)
  {
    cin >> n >>m;
    int val;
    int ans = 0;
    a.clear(); b.clear();
    for (int i = 0; i<n; ++i)
    {
      cin >> val;
      a.push_back(val);
    }
    for (int i = 0; i <m; ++i)
    {
      cin >> val;
      b.push_back(val);
    }
    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    for (int i =0; i< a.size(); ++i)
    {
      for (int j =0; j < b.size(); ++j)
      {
        if (a[i] <= b[j]) continue;
        ans += b.size() -j;
        break;
      }
    }
    cout << ans << '\n';
  }
}