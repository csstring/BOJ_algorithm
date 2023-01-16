#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t arr[101][12];
int n;
size_t ans;
const int mod = 1000000000;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =2; i<=10; ++i)
    arr[0][i] = 1;
  for (int i =1; i <n; ++i)
  {
    for (int j = 1; j <= 10; ++j)
    {
      arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mod;
    }
  }
  for (int i =1; i<= 10; ++i)
    ans += arr[n-1][i];
  cout << ans % mod;
}
