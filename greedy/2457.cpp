#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int startm, startd, endm,endd,s,e,f,ans;
vector<pair<int,int>> v;
int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int n;
int ft_trans(const int m, const int d)
{
  int tmp = 0;
  for (int i =0; i <m; ++i)
    tmp += arr[i];
  return tmp + d;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i){
    cin >> startm >> startd >> endm >> endd;
    v.push_back({ft_trans(startm, startd), ft_trans(endm,endd)});
  }
  sort(v.begin(), v.end());
  s = ft_trans(3,1);
  f = ft_trans(12,1);
  for (pair<int,int> cur : v)
  {
    if (cur.first > s){
      if (e <= s) break;
      ans++;
      s = e;
    }
    if (cur.first <= s) e = max(e, cur.second);
    if (e >= f) {
      ans++;
      break;
    }
  }
  if (e < f) cout << 0;
  else cout << ans;
}