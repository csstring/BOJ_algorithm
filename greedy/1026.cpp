#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int a[50], b[50];
int n;
size_t ans;
bool ft_comp(int a, int b)
{
  return a > b;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i =0; i <n; ++i)
    cin >> a[i];
  for (int i =0; i <n; ++i)
    cin >> b[i];
  sort(a, a+n);
  sort(b,b+n,ft_comp);
  for (int i =0; i <n; ++i)
    ans += a[i] * b[i];
  cout << ans;
}