#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <set>
using namespace std;
int n;
int b[1000005];
int arr[1000005];
set<int> s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i<n; ++i) cin >> b[i];
  s.insert(b[n-1]);
  for (int i = n-1; i>=0; --i)
  {
    //auto it = s.lower_bound(b[i]+1);
    auto it = s.upper_bound(b[i]);
    s.insert(b[i]);
    if (it == s.end()) continue;
    if (arr[b[i]] <= arr[*it] + 1) arr[b[i]] = arr[*it] +1;
    cout << b[i] << ' ' << *it <<' ' <<arr[b[i]] <<endl;
  }
  cout << *max_element(arr,arr+1000001)+1;
}