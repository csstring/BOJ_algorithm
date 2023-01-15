#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
queue<pair<size_t,size_t>> q;
int n,k,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>k;
  q.push({1,n});
  while (!q.empty())
  {
    pair<size_t,size_t> cur = q.front(); q.pop();
    if (cur.second == k)
    {
      cout << cur.first;
      return(0);
    }
    for (size_t nx : {cur.second * 2, cur.second * 10 +1})
    {
      if (nx < 1 || nx > k) continue;
      if (nx )
      q.push({cur.first+1, nx});
    }
  }
  cout << -1; 
}