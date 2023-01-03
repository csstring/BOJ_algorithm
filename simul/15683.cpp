//감시
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int n,m,ans;
int board[10][10];
int vis[10][10];
int dx[4] = {-1, 0,1,0};
int dy[4] = {0,1,0,-1};
vector<vector<tuple<int,int,int,int>>> cctv(6);
vector<tuple<int,int,int>> Point;
void initcctv()
{
  tuple<int,int,int,int> t1 = {1,0,0,0};
  tuple<int,int,int,int> t2 = {0,2,0,0};
  tuple<int,int,int,int> t3 = {0,0,3,0};
  tuple<int,int,int,int> t4 = {0,0,0,4};
  tuple<int,int,int,int> t5 = {1,0,3,0};
  tuple<int,int,int,int> t6 = {0,2,0,4};
  tuple<int,int,int,int> t7 = {1,2,0,0};
  tuple<int,int,int,int> t8 = {0,2,3,0};
  tuple<int,int,int,int> t9 = {0,0,3,4};
  tuple<int,int,int,int> t10 = {1,0,0,4};
  tuple<int,int,int,int> t11 = {1,2,0,4};
  tuple<int,int,int,int> t12 = {1,2,3,0};
  tuple<int,int,int,int> t13 = {0,2,3,4};
  tuple<int,int,int,int> t14 = {1,0,3,4};
  tuple<int,int,int,int> t15 = {1,2,3,4};
  cctv[1].push_back(t1); cctv[1].push_back(t2); cctv[1].push_back(t3); cctv[1].push_back(t4);
  cctv[2].push_back(t5); cctv[2].push_back(t6);
  cctv[3].push_back(t7); cctv[3].push_back(t8); cctv[3].push_back(t9); cctv[3].push_back(t10);
  cctv[4].push_back(t11); cctv[4].push_back(t12); cctv[4].push_back(t13); cctv[4].push_back(t14);
  cctv[5].push_back(t15);
}
void ft_draw(int x, int y, int dir, int val, int k)
{
  if (dir == 0) return;
  while (1)
  {
    x += dx[dir-1];
    y += dy[dir-1];
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (board[x][y] == 6) return;
    if (board[x][y] >= 1 && board[x][y] <= 5) continue;
    if (vis[x][y] != -1 && vis[x][y] != k) continue;
    board[x][y] = val;
    if (val == 0)
      vis[x][y] = -1;
    else
      vis[x][y] = k;
  }
}
void run(int k)
{
  if (k == Point.size()){
    int tempans = 0;
    for (int i = 0; i <n; ++i){
      for (int j = 0; j <m; ++j){
        if (board[i][j] == 0) tempans++;
      }
    }
    ans = min(ans, tempans);
    return;
  }
  int x,y,cctvinfo;
  tie(x,y,cctvinfo) = Point[k];
  vis[x][y] = k;
  for (int i = 0; i < cctv[cctvinfo].size(); ++i)
  {
    int d1,d2,d3,d4;
    tie(d1,d2,d3,d4) = cctv[cctvinfo][i];
    ft_draw(x,y,d1,'#',k); ft_draw(x,y,d2,'#',k); ft_draw(x,y,d3,'#',k); ft_draw(x,y,d4,'#',k);
    run(k + 1);
    ft_draw(x,y,d1,0,k); ft_draw(x,y,d2,0,k); ft_draw(x,y,d3,0,k); ft_draw(x,y,d4,0,k);
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i <n; ++i){
    fill(vis[i],vis[i] + m,-1);
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
      if (board[i][j] >= 1 && board[i][j] <= 5) Point.push_back({i,j,board[i][j]});
    }
  }
  ans = 100;
  initcctv();
  run(0);
  cout << ans;
}