#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,m,x,y,t;
int ft_gcd(int a, int b)
{
  if (a == 0) return b;
  return ft_gcd(b%a,a);
}
int ft_lcm(int a, int b)
{
  return a / ft_gcd(a,b) * b;
}
int ft_solve(int m,int n, int x, int y)
{
  if (m == x) x = 0;
  if (n == y) y = 0;
  int l = ft_lcm(m,n);
  for (int i =x; i <= l; i += m)
  {
    if (i == 0 ) continue;
    if (i % n == y) return i;
  }
  return -1;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    cin >> m >> n >> x >>y;
    cout << ft_solve(m,n,x,y) << '\n';
  }
}