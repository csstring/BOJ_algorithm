#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int arr[1001][1001][2];//n k 1,0
int n,k;
const int mod = 1000000003;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  arr[1][0][0] = 1;
  arr[1][1][1] = 1;
  for (int i = 2; i <= n; ++i)
  {
    for (int j = k; j >= 0; --j)
    {
      arr[i][j][0] = (arr[i-1][j][0] + arr[i-1][j][1]) %mod;
      if (j >= 1) arr[i][j][1] = arr[i-1][j-1][0] % mod;
    }
  }
  cout << (arr[n][k][0] + arr[n-1][k][1]) % mod;
}
