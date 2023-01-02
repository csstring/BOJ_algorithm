#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
int n;
stack<int> st;
vector<pair<int,int>> v;
void run(int k, int ans)
{
  if (k == n){
    if (st.top() < ans) st.push(ans);
    return;
  }
  if (v[k].first <= 0) {
    run(k+1, ans);
  }
  else
  {
    bool flag = false;
    for (int i = 0; i < n; ++i)//공격 대상 찾기
    {
      if (i == k) continue;
      if (v[i].first <= 0) continue;
      flag = true;
      v[i].first -= v[k].second;
      v[k].first -= v[i].second;
      if (v[i].first <= 0 && v[k].first <= 0) run(k+1, ans+2);
      else if (v[i].first > 0 && v[k].first > 0) run(k+1, ans);
      else run(k+1,ans + 1);
      v[i].first += v[k].second;
      v[k].first += v[i].second;
    }
    if (!flag) run(k+1, ans);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int s,w;
  for (int i = 0 ;i <n; ++i)
  {
    cin >> s >> w;
    v.push_back({s,w});
  }
  st.push(0);
  run(0,0);
  cout << st.top();
}