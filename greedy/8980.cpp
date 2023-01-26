#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,c,m,s,e,w,ans;
int truck[2001];
vector<tuple<int,int,int>> origin;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> c>> m;
  for (int i =0; i <m; ++i){
    cin >> s>>e>>w;
    origin.push_back({e,s,w});
  }
  sort(origin.begin(), origin.end());
  for (auto cur : origin)
  {
    tie(e,s,w) = cur;
    bool flag = true;
    for (int i = s; i <e; ++i)
    {
      w = min(w, c - truck[i]);
      if (w == 0){
        flag = false;
        break;
      }
    }
    if (flag){
      ans += w;
      for (int i =s; i <e; ++i){
        truck[i] += w;
      }
    }
  }
  cout << ans;
}