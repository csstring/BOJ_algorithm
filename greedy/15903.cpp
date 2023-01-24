#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[1000];
size_t n,m,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i =0;i < n; ++i)
    cin >> arr[i];
  while (m--)
  {
    sort(arr, arr+n);
    arr[0] += arr[1];
    arr[1] = arr[0];
  }
  for (int i =0; i <n; ++i)
    ans += arr[i];
  cout << ans;
}