#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
ssize_t cnt,n,minval,val,tmpcnt;
vector<ssize_t> v;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i <n; ++i)
  {
    cin >> val;
    v.push_back(val);
  }
  sort(v.begin(), v.end());
  minval = INT64_MIN;
  for (int i =0; i < v.size(); ++i)
  {
    
  }
}