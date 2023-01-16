#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
ssize_t arr[2000005];
const int mod = 1000000000;
const int r = 1000000;
int n;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  arr[r] = 0;
  arr[r+1] = 1;
  if (n >= 0)
  {
    for (int i = 2; i<=n; ++i)
    {
      arr[r+i] = (arr[r+i-1] + arr[r+i-2]) % mod;
    }
  }
  else
  {
    for (int i = -1; i>=n; --i)
    {
      arr[r+i] = (arr[r+i+2] - arr[r+i+1]) % mod;
    }
  }
  if (arr[r+n] >0) cout << 1;
  else if (arr[r+n] ==0) cout << 0;
  else cout << -1;
  cout << '\n';
  cout << abs(arr[r+n]) %mod;
}