//테트로미노
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
#define X first
#define Y second
vector<pair<int,int>> stick[7][4]; //index,dir(x,y);
int board[500][500];
int n,m,ans;
int findmaxR(int k)
{
  int mx = 0;
  int my = 0;
  int res = 0;
  for (int i = 0; i < 4;++i){
    mx = stick[k][0][i].X;
    my = stick[k][0][i].Y;
    res = max(res, my);
    res = max(res, mx);
  }
  return res + 1;
}

void ft_initStick()
{
  int maxR;
  stick[0][0] = {{0,0},{0,1},{0,2},{0,3}};
  stick[1][0] = {{0,0},{0,1},{1,0},{1,1}};
  stick[2][0] = {{0,0},{1,0},{2,0},{2,1}};
  stick[3][0] = {{0,0},{1,0},{1,1},{2,1}};
  stick[4][0] = {{0,0},{0,1},{0,2},{1,1}};
  stick[5][0] = {{0,1},{1,1},{2,1},{2,0}};
  stick[6][0] = {{0,1},{1,1},{1,0},{2,0}};
  for (int k =0; k <7; ++k)
  {
    maxR = findmaxR(k);
    for (int tmp = 0; tmp < 3; ++tmp){
      int minx = 4;
      int miny = 4;
      for (int i = 0; i < 4; ++i){
        pair<int,int> cur = {stick[k][tmp][i].Y, maxR - 1 - stick[k][tmp][i].X};
        minx = min(minx, cur.X);
        miny = min(miny, cur.Y);
        stick[k][tmp + 1].push_back(cur);
      }
      for (int i = 0; i < 4;++i){
        stick[k][tmp+1][i].X -= minx;
        stick[k][tmp+1][i].Y -= miny;
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  ft_initStick();
  
  cin >> n >> m;
  for (int i = 0; i<n; ++i){
    for (int j =0; j <m; ++j){
      cin >> board[i][j];
    }
  }
  for (int k = 0; k <7; ++k){
    for (int dir = 0; dir <4; ++dir){
      for (int x = 0; x <n; ++x){
        for (int y = 0; y <m; ++y)
        {
          int tans = 0;
          for (int i = 0; i < 4; ++i)
          {
            pair<int,int> cur = stick[k][dir][i];
            int curX = cur.X + x;
            int curY = cur.Y + y;
            if (curX < 0 || curY < 0 || curX >= n|| curY >=m) continue;
            tans += board[curX][curY];
          }
          ans = max(ans, tans);
        }
      }
    }
  }
  cout << ans;
}