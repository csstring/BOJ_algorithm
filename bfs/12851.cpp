#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
int board[100002];
int Count[100002];
int n,k;
queue<int> q;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  fill(board, board+100002, -1);
  fill(Count, Count+100002, 1);
  int time =0;
  q.push(n);
  board[n] = 0;
  while (!q.empty())
  {
    int cur = q.front(); q.pop();
    if (time != board[cur])
    {
      time++;
      if (board[k] != -1) break;
    }
    for (int nx : {cur-1,cur+1, cur*2})
    {
      if (nx < 0|| nx > 100000) continue;
      if (board[nx] == board[cur] +1) Count[nx] += Count[cur];
      if (board[nx] != -1) continue;
      board[nx] = board[cur] + 1;
      Count[nx] = Count[cur];
      q.push(nx);
    }
  }
  cout << board[k] << '\n' << Count[k];
}