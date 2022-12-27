#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
int dist[100005];
int n, k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> q;
  cin >> n >> k;
  fill(dist, dist + 100002, -1);
  dist[n] = 0;
  q.push(n);
  if (n == k)
  {
    cout << 0;
    return (0);
  }
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    for(int nx : {cur-1, cur+1, 2*cur})
    {
      if (nx < 0 || nx > 100000) continue;
      if (nx == k){
        cout << dist[cur] + 1;
        return(0);
      }
      if (dist[nx] != -1) continue;
      q.push(nx);
      dist[nx] = dist[cur] + 1;
    }
  }
}