#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
int n,k,ans;
int arr[10];
using namespace std;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i =0; i < n; ++i)
    cin >> arr[i];
  for (int i = n-1; i >=0; --i)
  {
    ans += k / arr[i];
    k = k % arr[i];
  }
  cout << ans;
}