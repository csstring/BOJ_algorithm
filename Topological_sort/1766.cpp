#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,m,in,out;
vector<int> v[32001];
priority_queue<int,vector<int>, greater<int>> pq;
queue<int> q;
int deg[32001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i=0; i <m; ++i){
    cin >> in >> out;
    deg[out]++;
    v[in].push_back(out);
  }
  for (int i =1; i <=n; ++i){
    if (deg[i] == 0) pq.push(i);
  }
  while (!pq.empty())
  {
    int cur = pq.top(); pq.pop();
    cout << cur << ' ';
    for (int nxt : v[cur])
    {
      deg[nxt]--;
      if (deg[nxt] == 0) pq.push(nxt);
    }
  }
}