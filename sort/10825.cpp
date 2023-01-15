#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<tuple<string,int,int,int>> v;
int a,b,c;
string name;
int n;
bool ft_comp(const tuple<string,int,int,int>& s, const tuple<string,int,int,int>& e)
{
  int a1,a2,b1,b2,c1,c2;
  string name1,name2;
  tie(name1,a1,b1,c1) = s;
  tie(name2,a2,b2,c2) = e;
  if (a1 != a2)
    return a1 > a2;
  else
  {
    if (b1 != b2)
      return b1 < b2;
    else
    {
      if (c1 != c2)
        return c1 > c2;
      else
      {
        return name1 < name2;
      }
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i< n; ++i)
  {
    cin >> name >> a >> b>> c;
    v.push_back({name,a,b,c});
  }
  sort(v.begin(),v.end(),ft_comp);
  for (int i = 0; i <n; ++i)
  {
    cout << get<0>(v[i]) << '\n';
  }
}