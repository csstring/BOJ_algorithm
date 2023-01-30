#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int deg[32002];
int n,m,in,out;
queue<int> q;
vector<int> v[32002];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i =0; i<m; ++i){
    cin >> in >> out;
    deg[out]++;
    v[in].push_back(out);
  }
  for (int i =1; i<=n; ++i){
    if (deg[i] == 0) q.push(i); 
  }
  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    cout << cur << ' ';
    for (int nxt : v[cur])
    {
      deg[nxt]--;
      if (deg[nxt] == 0) q.push(nxt);
    }
  }
}