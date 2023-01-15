#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
bool arr[1001];
vector<int> v;
int n,val,cnt,tcnt;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i)
  {
    cin >> val;
    v.push_back(val);
  }
  sort(v.begin(), v.end());
  for (int i =0; i < v.size(); ++i)
  {
    if (arr[v[i]]) continue;
    cnt++;
    arr[v[i]] = true;
  }
  cout << cnt;
}