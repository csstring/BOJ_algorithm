#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<pair<int,int>> v;
int n,val;
bool ft_comp(const pair<int,int>& a, const pair<int,int>& b)
{
  return a.second > b.second;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> val;
  for (int i =0; i < n; ++i)
  {
    cin >> val;
    bool flag = false;
    for (auto& cur : v)
    {
      if (val == cur.first)
      {
        cur.second++;
        flag =true;
        break;
      }
    }
    if (flag == false) v.push_back({val,1});
  }
  stable_sort(v.begin(), v.end(),ft_comp);
  for (auto& cur : v)
  {
    for (int i = 0; i < cur.second; ++i)
    {
      cout << cur.first << ' ';
    }
  }
}