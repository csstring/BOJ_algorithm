#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n, m;
int borad[1000][1000];
int Time[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int, int>> q;
  cin >> m >> n;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      cin >> borad[i][j];
      if (borad[i][j] == 1)
        q.push({i, j});
      if (borad[i][j] == 0)
        Time[i][j] = -1;
    }
  while (!q.empty())
  {
    pair<int, int> cur = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
      if (Time[nx][ny] != -1) continue;
      Time[nx][ny] = Time[cur.X][cur.Y] + 1;
      //borad[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      if (Time[i][j] == -1)
      {
        cout << "-1";
        return (0);
      }
      ans = max(ans, Time[i][j]);
    }
  cout << ans;
}