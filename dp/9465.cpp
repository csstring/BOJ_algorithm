#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
size_t board[3][100001];
size_t arr[3][100001];
int t,n;
size_t ans;
void init()
{
  cin >> n;
  for (int tmp = 1; tmp <= 2; ++tmp)
    for (int i =1; i <= n; ++i)
      cin >> board[tmp][i];
  for (int tmp =0; tmp <3; ++tmp)
    fill(arr[tmp] +1, arr[tmp] +1+n,0);
  arr[1][1] = board[1][1];
  arr[2][1] = board[2][1];
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    ans = 0;
    init();
    for (int i =2; i <= n; ++i)
    {
      arr[0][i] = max(arr[1][i-1], arr[2][i-1]);
      arr[1][i] = max(arr[0][i-1], arr[2][i-1]) + board[1][i];
      arr[2][i] = max(arr[0][i-1], arr[1][i-1]) + board[2][i];
    }
    for (int i=0; i <3; ++i)
      ans = max(ans, arr[i][n]);
    cout << ans << '\n';
  }
}