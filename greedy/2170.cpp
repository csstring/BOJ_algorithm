#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
stack<pair<int,int>> st;
vector<pair<int,int>> v;
int n,s,e,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i){
    cin >> s >> e;
    v.push_back({s,e});
  }
  sort(v.begin(), v.end());
  st.push(v[0]);
  for (pair<int,int> cur : v)
  {
    if (st.top().second >= cur.first) 
      st.top().second = max(st.top().second, cur.second);
    else
      st.push(cur);
  }
  while (!st.empty()){
    ans += st.top().second - st.top().first;
    st.pop();
  }
  cout << ans;
}