#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
queue<int> ret,q;
vector<int> v[1001];
int deg[1001];
int n,m,t,in,out;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m;
  for (int i =0; i <m; ++i){
    cin >> t >> in;
    while(--t)
    {
      cin >> out;
      v[in].push_back(out);
      deg[out]++;
      in = out;
    }
  }
  for (int i=1; i <=n;++i){
    if (deg[i] == 0) q.push(i);
  }
  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    ret.push(cur);
    for (int nxt : v[cur])
    {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
  if (ret.size() != n) cout << 0;
  else{
    while (!ret.empty()){
      cout << ret.front()<<'\n';
      ret.pop();
    }
  }
}