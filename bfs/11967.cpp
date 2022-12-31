//불켜키
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int light[101][101];
int vis[101][101];
vector<pair<int,int>> adj[101][101];
int n, m, x,y,a,b,ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; ++i){
    cin >> x >> y >> a >> b;
    adj[x][y].push_back({a,b});
  }
  vis[1][1] = 1; light[1][1] = 1;
  queue<pair<int,int>> q;
  q.push({1,1});
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    for (auto nxp : adj[cur.X][cur.Y])
    {
      if (nxp.X < 1 || nxp.Y < 1 || nxp.X > n || nxp.Y > n) continue;
      if (light[nxp.X][nxp.Y]) continue;
      int flag = 0;
      light[nxp.X][nxp.Y] = 1;
      for (int dir =0; dir <4; ++dir)
      {
        int nx = nxp.X + dx[dir];
        int ny = nxp.Y + dy[dir];
        if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
        if (vis[nx][ny] == 0) continue;
        flag = 1; break;
      }
      if (flag)
      {
        vis[nxp.X][nxp.Y] = 1;
        q.push({nxp.X,nxp.Y});
      }
    }
    for (int dir =0; dir <4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
      if (light[nx][ny] == 0 || vis[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      q.push({nx,ny});
    }
  }
  for (int i = 1; i < n + 1; ++i){
    for (int j = 1; j < n + 1; ++j){
      if (light[i][j] == 1) ans++;
    }
  }
  cout << ans;
}