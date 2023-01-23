#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int t,n;
size_t ans;
int board[1000000];
bool ft_comp(const int& a, const int& b)
{
  return a > b;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--)
  {
    ans = 0;
    cin >> n;
    int tmp;
    for (int i =0; i <n; ++i)
      cin >> board[i];
    if (is_sorted(board, board+n, ft_comp)){
      cout << 0 <<'\n';
      continue;
    }
    tmp = *max_element(board, board+n);
    for (int i =0; i <n; ++i)
    {
      if (board[i] == tmp)
        tmp = *max_element(board+i+1, board+n);
      else
        ans += tmp - board[i];
    }
    cout << ans << '\n';
  }
}