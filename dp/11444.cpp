#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t dp[2][2],n,ans;
const int mod = 1000000007;
void solve(size_t k)
{
  if (k == 1) return;
  solve(k/2);
  size_t v1,v2,v3,v4;
  tie(v1,v2,v3,v4) = {dp[0][0],dp[0][1],dp[1][0],dp[1][1]};
  dp[0][0] = (v1*v1 + v2*v3) %mod;
  dp[0][1] = (v1*v2 + v2*v4) %mod;
  dp[1][0] = (v3*v1 + v4*v3) %mod;
  dp[1][1] = (v3*v2 + v4*v4) %mod;
  if (k %2)
  {
    tie(v1,v2,v3,v4) = {dp[0][0],dp[0][1],dp[1][0],dp[1][1]};
    dp[0][0] = (v1 + v2) %mod;
    dp[0][1] = (v1) %mod;
    dp[1][0] = (v3 + v4) %mod;
    dp[1][1] = (v3) %mod;
  }
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  dp[0][0] = 1;
  dp[0][1] = 1;
  dp[1][0] = 1;
  dp[1][1] = 0;
  solve(n);
  cout << (dp[0][1] %mod);
}