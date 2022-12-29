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
char borad[30][30][30];
int Exit[30][30][30];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1)
  {
    cin >> h >> n >> m;
    if (h == 0 && m == 0 && h == 0) break;
    queue<tuple<int,int,int>> eq;
    for (int i = 0; i < h; ++i){
      for (int j = 0; j < n; ++j){
        for (int k = 0; k < m; ++k)
        {
          cin >> borad[j][k][i];
          if (borad[j][k][i] == 'S')
          {
            eq.push({j,k,i});
            Exit[j][k][i] = 0;
          }
          else
            Exit[j][k][i] = -1;
        }
      }
    }
    bool flag = 0;
    while (!eq.empty() && flag == 0)
    {
      auto cur = eq.front();
      int curx, cury,curz;
      tie(curx,cury,curz) = cur;
      eq.pop();
      for (int dir = 0 ; dir < 6; ++dir)
      {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        int nz = curz + dz[dir];
        if (nx < 0 || ny < 0|| nz < 0 || nx >= n || ny >= m || nz >= h) continue;
        if (borad[nx][ny][nz] == 'E'){
          cout <<"Escaped in " << Exit[curx][cury][curz] + 1 <<" minute(s).\n";
          flag = 1;
          break;
        }
        if (borad[nx][ny][nz] == '#' || Exit[nx][ny][nz] != -1) continue;
        Exit[nx][ny][nz] = Exit[curx][cury][curz] + 1;
        eq.push({nx,ny,nz});
      }
    }
    if (flag == 0)
      cout << "Trapped!\n";
  }
}