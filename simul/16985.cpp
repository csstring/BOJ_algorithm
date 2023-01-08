//maaaaaaaze
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
int board[5][5][5][4];//층, n,m,dir
int vis[1024][5][5][5];
int cube[5][5][5];
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int ans;
void ft_rot(int k)
{
  for (int tmp = 0; tmp <3; ++tmp)
    for (int i = 0; i < 5; ++i)
      for (int j = 0; j < 5; ++j)
        board[k][i][j][tmp + 1] = board[k][4-j][i][tmp];
}

void run(int vtime)
{
    if (cube[0][0][0] == 0 || cube[4][4][4] == 0) return;
    for (int i =0; i <5; ++i){
      for (int j =0; j <5; ++j){
        fill(vis[vtime][i][j], vis[vtime][i][j] +5, 0);
      }
    }
    queue<tuple<int,int,int>> q;
    vis[vtime][0][0][0] = 1;
    q.push({0,0,0});
    while (!q.empty())
    {
      int curx,cury,curz;
      tie(curz,curx,cury) = q.front(); q.pop();
      for (int dir = 0; dir < 6; ++dir)
      {
        int nx = curx + dx[dir];
        int ny = cury + dy[dir];
        int nz = curz + dz[dir];
        if (nx < 0 || ny < 0 || nz < 0 || nx >=5 || ny >= 5 || nz >=5) continue;
        if (cube[nz][nx][ny] == 0 || vis[vtime][nz][nx][ny] != 0) continue;
        vis[vtime][nz][nx][ny] = vis[vtime][curz][curx][cury] + 1;
        q.push({nz,nx,ny});
      }
    }
    if (vis[vtime][4][4][4] != 0){
      ans = min(ans,vis[vtime][4][4][4] - 1);
    }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int k = 0; k < 5; ++k){
    for (int i = 0; i <5; ++i){
      for (int j = 0; j <5; ++j){
        cin >> board[k][i][j][0];
      }
    }
    ft_rot(k);
  }
  ans = INT32_MAX;
  int arr[5] = {0,1,2,3,4};
  do{
    for (int total = 0; total < 1024; ++total)
    {
      int mod = total;
      for (int k = 0; k < 5; ++k)
      {
        int dir = mod % 4;
        mod /= 4;
        for (int i = 0; i < 5; ++i){
          for (int j = 0; j <5; ++j){
            cube[k][i][j] = board[arr[k]][i][j][dir];
          }
        }
      }
      run(total);
    }
  }while(next_permutation(arr,arr+5));
  if (ans == INT32_MAX) cout << -1;
  else cout << ans;
}