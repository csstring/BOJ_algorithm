#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[1001];
int n;
size_t ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> board[i];
  sort(board+1, board+n+1);
  for (int i =1; i <= n; ++i){
    board[i] = board[i] + board[i-1];
    ans += board[i];
  }
  cout << ans;
}