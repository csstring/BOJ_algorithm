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
  for (int i =1; i < n; ++i)
  {
    cin >> val;
    if (v.back() < val){
      v.push_back(val);
      s.push_back(i);
      ans.push_back(val);
      auto it = is_sorted_until(s.rbegin(), s.rend(), greater<int>());
      int dis = distance(it,s.rend());
      for (int j = dis; j <v.size(); ++j)
      {
        ans[j] = v[j];
      }
        //P = ans.size()-1;
    } 
    else{
      auto it = lower_bound(v.begin(), v.end(), val);
      *it = val;
      int dis = distance(v.begin(), it);
      s[dis] = i;
      //if (dis < P) P = dis;
    } 
  }
  cout << ans.size()<< '\n';
  for (int i =0; i < ans.size(); ++i)
    cout << ans[i] << ' ';
    /*
  cout << '\n';
  for (int i =0; i < v.size(); ++i)
    cout << v[i] << ' ';
  cout << '\n';
  for (int i =0; i < s.size(); ++i)
    cout << s[i] << ' ';*/
}