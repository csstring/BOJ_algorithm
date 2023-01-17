#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[10][1001];
int n,ans;
const int mod = 10007;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i =0; i <10; ++i)
    arr[i][1] = 1;
  cin >> n;
  for (int i =2; i <=n; ++i)
  {
    for (int j = 0; j<10; ++j)
    {
      for (int k =0; k <=j; ++k)
      {
        arr[j][i] += arr[k][i-1];
      }
      arr[j][i] = arr[j][i] % mod;
    }
  }
  for (int i =0; i <10; ++i)
    ans += arr[i][n];
  cout << ans % mod;
}