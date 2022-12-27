#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int borad[500][500];
bool vis[500][500];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int max_pic, n, m, num;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> borad[i][j];
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j)
    {
      if (borad[i][j] == 0 || vis[i][j]) continue;
      num++;
      queue<pair<int,int>> q;
      vis[i][j] = true;
      q.push({i,j});
      int area = 0;
      while (!q.empty())
      {
        area++;
        pair<int,int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir)
        {
          int nx = cur.X + dx[dir];
          int ny = cur.Y + dy[dir];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vis[nx][ny] || borad[nx][ny] == 0) continue;
          vis[nx][ny] = 1;
          q.push({nx, ny});
        }
      }
      max_pic = max(max_pic, area);
    }
  }
  cout << num << '\n' << max_pic;
}