#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
vector<int> v;
int n,val;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> val;
  v.push_back(val);
  while (--n)
  {
    cin >> val;
    if (v.back() < val) v.push_back(val);
    else *lower_bound(v.begin(), v.end(), val) = val;
  }
  cout << v.size();
}