#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
set<int> s;
int n,k,val;
int arr[10001];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i =0; i <n; ++i)
  {
    cin >> val;
    if (val > k) continue;
    s.insert(val);
  }
  for (auto& it : s)
  {
    arr[it] = 1;
    for (int i =1; i + it <= k; ++i)
    {
      if (arr[i] == 0) continue;
      if (arr[i+it] == 0) arr[i+it] = arr[i] + 1;
      else arr[i +it] = min(arr[i+it], arr[i] + 1);
    }
  }
  if (arr[k] ==0) cout << -1;
  else cout << arr[k]; 
}