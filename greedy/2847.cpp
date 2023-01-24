#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int n,ans;
int board[100];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i< n; ++i)
    cin >> board[i];
  for (int i = n-2; i >=0 ; --i)
  {
    if (board[i] < board[i+1]) continue;
    ans += board[i] - (board[i+1] -1);
    board[i] = board[i+1] -1;
  }
  cout << ans;
}