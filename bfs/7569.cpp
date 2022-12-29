#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int n,m,h;
int borad[100][100][100];
int day[100][100][100];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> h;
  queue<tuple<int,int,int>> q;
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < n; ++j){
      for (int k = 0; k < m; ++k)
      {
        cin >> borad[j][k][i];
        if (borad[j][k][i] == 1){
          day[j][k][i] = 0;
          q.push({j,k,i});
        }
        else 
          day[j][k][i] = -1;
      }
    }
  }
  while (!q.empty())
  {
    tuple<int,int,int> cur = q.front();
    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;
    q.pop();
    for (int dir = 0; dir < 6; ++dir)
    {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      int nz = curZ + dz[dir];
      if (nx < 0 || ny < 0|| nz < 0 || nx >= n || ny >= m || nz >= h) continue;
      if (day[nx][ny][nz] != -1 || borad[nx][ny][nz] == -1) continue;
      day[nx][ny][nz] = day[curX][curY][curZ] + 1;
      borad[nx][ny][nz] = 1;
      q.push({nx,ny,nz});
    }
  }
  int max_day = 0;
  for (int i = 0; i < h; ++i){
    for (int j = 0; j < n; ++j){
      for (int k = 0; k < m; ++k)
      {
        if (borad[j][k][i] == 0)
        {
          cout << -1;
          return(0);
        }
        if (borad[j][k][i] == 1)
        {
          max_day = max(max_day,day[j][k][i]);
        }
      }
    }
  }
  cout << max_day;
}