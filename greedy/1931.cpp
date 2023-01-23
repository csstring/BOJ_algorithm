#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int s,e,n,ans;
vector<pair<int,int>> v;
bool ft_comp(pair<int,int>& a, pair<int,int>& b)
{
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i){
    cin >> s >>e;
    v.push_back({s,e});
  }
  sort(v.begin(), v.end(), ft_comp);
  int start = v[0].first;
  int end = v[0].second;
  ans++;
  for (auto it = v.begin()+1; it != v.end(); ++it)
  {
    if (it->first < end) continue;
    end = it->second;
    ans++;
  }
  cout << ans;
}