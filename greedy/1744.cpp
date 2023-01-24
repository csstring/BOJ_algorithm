#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,ans,val;
vector<int> p,m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <n; ++i)
  {
    cin >> val;
    if (val > 0) p.push_back(val);
    else m.push_back(val);
  }
  sort(p.rbegin(), p.rend());
  sort(m.begin(), m.end());
  for (int i =0; i < p.size(); i = i+2)
  {
    if (i != p.size()-1) ans += max(p[i] * p[i+1], p[i]+ p[i+1]);
    else ans += p[i]; 
  }
  for (int i =0; i < m.size(); i = i+2)
  {
    if (i != m.size()-1) ans += m[i] * m[i+1];
    else ans += m[i]; 
  }
  cout << ans;
}