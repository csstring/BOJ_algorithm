#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n,m,v,k,c,tmp;
size_t ans;
pair<int,int> ju[1000001];//가격, 무게
multiset<int> ms;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i =0; i < n; ++i){
    cin >> ju[i].second;
    cin >> ju[i].first;
  }
  sort(ju,ju+n+1);
  for (int i =0; i <k; ++i){
    cin >> tmp;
    ms.insert(tmp);
  }
  for (int i = n; i>=0; --i)
  {
    if (ms.empty()) break;
    auto it = ms.upper_bound(ju[i].second);
    if (it != ms.begin()&&*prev(it) == ju[i].second) --it;
    if (it == ms.end()) continue;
    ans += ju[i].first;
    ms.erase(it);
  }
  cout << ans;
}