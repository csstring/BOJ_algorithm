//비밀번호 제작 (bitmask)
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
int n,m,p;
int board[1000005];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> q;
  cin >> n >> m;
  fill(board, board + n + 1, -1);
  for (int i = 0; i < m; ++i)
  {
    cin >> p;
    board[p] = 0;
    q.push(p);
  }
  while (!q.empty())
  {
    int nx = 0;
    int cur = q.front(); q.pop();
    for (int k = 0; k < 31; ++k)
    {
      if (cur & (1 << k))
        nx = cur & ~(1 << k);
      else
        nx = cur | (1 << k);
      if (nx > n) continue;
      if (board[nx] != -1) continue;
      q.push(nx);
      board[nx] = board[cur] + 1;
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    ans = max(ans, board[i]);
  cout << ans;
}