#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx2[8] = {1,2,2,1,-1,-2,-2,-1};
int dy2[8] = {-2,-1,1,2,2,1,-1,-2};
int dx1[4] = {1,0,-1,0};
int dy1[4] = {0,1,0,-1};
int n,m,k;
int board[201][201];
int Count[32][201][201];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> m >> n;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
    }
  }
  Count[0][0][0] = 1;
  queue<tuple<int,int,int>> q;
  q.push({0,0,0});
  while (!q.empty())
  {
    auto cur = q.front(); q.pop();
    int curX, curY, jump;
    tie(curX, curY, jump) = cur;
    for (int dir = 0; dir< 4; ++dir)
    {
      int nx = curX + dx1[dir];
      int ny = curY + dy1[dir];
      if (nx < 0 || ny < 0|| nx >= n || ny >= m) continue;
      if (board[nx][ny] == 1 || Count[jump][nx][ny] != 0) continue;
      Count[jump][nx][ny] = Count[jump][curX][curY] + 1;
      q.push({nx,ny,jump});
    }
    if (jump < k)
    {
      for (int dir = 0; dir< 8; ++dir)
      {
        int nx = curX + dx2[dir];
        int ny = curY + dy2[dir];
        if (nx < 0 || ny < 0|| nx >= n || ny >= m) continue;
        if (board[nx][ny] == 1 || Count[jump + 1][nx][ny] != 0) continue;
        Count[jump + 1][nx][ny] = Count[jump][curX][curY] + 1;
        q.push({nx,ny,jump + 1});
      }
    }
  }
  int ans = INT32_MAX;
  for (int i = 0; i < k + 1; ++i){
    if (Count[i][n -1][m - 1] != 0)
    {
      ans = min(ans, Count[i][n-1][m-1] - 1);
    }
  }
  if (ans != INT32_MAX)
    cout << ans;
  else
    cout << -1;
}