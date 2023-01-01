//숨바꼭질 5
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int board[2][500005];
int n,k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  fill(board[0], board[0] + 500001, -1);
  fill(board[1], board[1]+ 500001, -1);
  queue<pair<int,int>> q;
  board[0][n] = 0;
  q.push({n,0});
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    int nxt = (cur.Y + 1) % 2;
    for (int nx : {cur.X + 1, cur.X -1, 2*cur.X})
    {
      if (nx < 0 || nx > 500000) continue;
      if (board[nxt][nx] != -1) continue;
      q.push({nx, nxt});
      board[nxt][nx] = board[cur.Y][cur.X] + 1;
    }
  }
  int ans = 0;
  int time = 0;
  while (k <= 500000)
  {
    if (board[time%2][k] != -1 && time >= board[time % 2][k])
    {
      cout << time;
      return(0);
    }
    time++;
    k += time;
  }
  cout << -1;
}