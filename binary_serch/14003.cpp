#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<int> v,ans,s;
int n,val,P;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> val;
  v.push_back(val);
  ans.push_back(val);
  s.push_back(0);
  P = 1;
  for (int i =1; i < n; ++i)
  {
    cin >> val;
    if (v.back() < val){
      v.push_back(val);
      if (s.begin()+P == s.end() ||is_sorted(s.begin()+P, s.end())){
        ans.assign(v.begin(), v.end());
        P = ans.size();
      }
    } 
    else{
      auto it = lower_bound(v.begin(), v.end(), val);
      *it = val;
      int dis = distance(v.begin(), it);
      s[dis] = i;
      if (dis < P) P = dis;
    } 
  }
  cout << ans.size()<< '\n';
  for (int i =0; i < ans.size(); ++i)
    cout << ans[i] << ' ';
  cout << endl;
  for (int i =0; i < v.size(); ++i)
    cout << v[i] << ' ';
}