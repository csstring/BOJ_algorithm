#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int n,m,k,total,x,y,ans;
int board[50][50];
bool vis[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> total;
  for (int t = 0; t < total; ++t)
  {
    ans = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i){
      fill(board[i], board[i] + m, 0);
      fill(vis[i], vis[i] + m, 0);
    }
    for (int i = 0; i < k; ++i){
      cin >> x >> y;
      board[x][y] = 1;
    }
    for (int i = 0; i< n; ++i){
      for (int j = 0; j < m; ++j)
      {
        if (board[i][j] == 0 || vis[i][j] == 1) continue;
        ans++;
        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i, j});
        while (!q.empty())
        {
          pair<int,int> cur = q.front();
          q.pop();
          for (int dir = 0; dir < 4; ++dir)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx <0 || ny < 0 || nx == n || ny == m) continue;
            if (board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
            vis[nx][ny] = 1;
            q.push({nx, ny});
          }
        }
      }
    }
    cout <<ans << '\n';
  }
}