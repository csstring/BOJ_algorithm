#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t a,b;
size_t dp[66];
size_t solve(size_t x)
{
  if (x <= 1) return x;
  int tx = 0;
  while (1UL << tx <= x) tx++;
  tx--;
  size_t c = x - (1UL << tx) +1;
  return c + dp[tx] + solve(x - (1UL<< tx));
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  dp[1] = 1;
  for (int i =2; i <=63; ++i){
    dp[i] = dp[i-1] * 2 + (1UL << (i-1)); 
  }
  cin >> a>>b;
  a--;
  cout << solve(b) - solve(a);
}