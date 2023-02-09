#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,x,y,dl,ans;
struct cmp
{
  bool operator()(pair<int,int> a, pair<int,int> b)
  {
    if (a.first != b.first)
      return a.first > b.first;
    return a.second < b.second;
  }
};
priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i)
  {
    cin >> x>>y;
    pq.push({x,y});
  }
  while (!pq.empty())
  {
    if (dl < pq.top().first)
    {
      ans += pq.top().second;
      dl++;
      pq.pop();
    }
    else{
      pq.pop();
    }
  }
  cout << ans;
}