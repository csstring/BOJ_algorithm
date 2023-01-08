//로봇청소기
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m,x,y,dir,ans;
int board[50][50];
bool vis[50][50];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n>>m >>x >>y >>dir;
  for (int i =0; i< n; ++i){
    for (int j = 0; j <m; ++j){
      cin >> board[i][j];
    }
  }
  while(1)
  {
    bool flag = false;
    if (vis[x][y] == 0){
      vis[x][y] = 1; ans++;
    }
    for (int tmp = 0; tmp < 4; ++tmp)
    {
      dir = (dir + 3) %4;
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
      x = nx; y = ny;
      flag =true;
      break;
    }
    if (flag) continue;
    int nx = x + dx[(dir +2) % 4];
    int ny = y + dy[(dir +2) % 4];
    if (board[nx][ny] == 1) break;
    x = nx; y = ny;
  }
  cout << ans;
}