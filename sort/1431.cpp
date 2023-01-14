#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n;
string str;
vector<string> v;
bool ft_comp(string& a, string& b)
{
  if (a.size() != b.size())
    return a.size() < b.size();
  else
  {
    int ta = 0;
    int tb = 0;
    for (int i = 0; i < a.size(); ++i){
      if (isdigit(a[i])) ta += a[i] - 48;
    }
    for (int i = 0; i < b.size(); ++i){
      if (isdigit(b[i])) tb += b[i] - 48;
    }
    if (ta != tb)
      return ta < tb;
    return a < b;
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0 ; i < n; ++i){
    cin >> str;
    v.push_back(str);
  }
  sort(v.begin(), v.end(), ft_comp);
  for (int i = 0; i < n; ++i)
    cout << v[i] << '\n';
}