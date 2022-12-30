#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[100005];
int n,k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  fill(board, board + 100005, -1);
  board[n] = n;
  queue<int> q;
  q.push(n);
  while (!q.empty() && board[k] == -1)
  {
    int cur = q.front(); q.pop();
    for (int nx : {cur + 1, cur -1, cur *2})
    {
      if (nx < 0 || nx > 100000) continue;
      if (board[nx] != -1) continue;
      board[nx] = cur;
      q.push(nx);
    }
  }
  int ans = 0;
  int cur = k;
  stack<int> st;
  while (cur != n)
  {
    ans++;
    st.push(cur);
    cur = board[cur];
  }
  cout << ans << '\n';
  cout << n << ' ';
  while (!st.empty())
  {
    cout << st.top() << ' ';
    st.pop();
  }
}