#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int dp[1001][1001];
int n, k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>k;
  for (int i =1; i <=n; ++i){
    dp[i][i] = 1;
    dp[i][0] = 1;
  }
  for (int i = 2; i <= n; ++i)
  {
    for (int j = i-1; j >=1; --j){
      dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])%10007;
    }
  }
  cout << dp[n][k] % 10007;
}