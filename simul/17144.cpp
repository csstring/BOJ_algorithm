//미세먼지 안녕!
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
#define X first
#define Y second
pair<int,int> down;
pair<int,int> up;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int board1[50][50];
int board2[50][50];
int T,n,m,ans;
queue<pair<int,int>> q;
void airPress()
{
  //down
  for (int i = down.X + 2; i <n; ++i)
    board2[i-1][down.Y] = board2[i][down.Y];
  for (int i = down.Y + 1; i < m; ++i)
    board2[n-1][i -1] = board2[n-1][i];
  for (int i = n-2; i >= down.X; --i)
    board2[i + 1][m-1] = board2[i][m-1];
  for (int i = m-2; i > down.Y; --i)
    board2[down.X][i+1] = board2[down.X][i];
  //up
  for (int i = up.X-2; i >= 0; --i)
    board2[i+1][up.Y] = board2[i][up.Y];
  for (int i = up.Y + 1; i < m; ++i)
    board2[0][i -1] = board2[0][i];
  for (int i = 1; i <= up.X; ++i)
    board2[i -1][m-1] = board2[i][m-1];
  for (int i = m-2; i > up.Y; --i)
    board2[up.X][i+1] = board2[up.X][i];
  board2[up.X][up.Y+1] = 0;
  board2[down.X][down.Y+1] = 0;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >>m >> T;
  bool flag = false;
  for (int i = 0; i < n; ++i){
    for (int j = 0 ; j < m; ++j){
      cin >> board1[i][j];
      if (board1[i][j] == -1 && flag == false){
        flag = true;
        up.X = i; up.Y =j;
      }
      if (board1[i][j] == -1 && flag == true){
        down.X = i; down.Y = j;
      }
      if (board1[i][j] > 0) q.push({i,j});
    }
  }
  int time = 0;
  while (time != T)
  {
    time++;
    while (!q.empty())
    {
      pair<int,int> cur =q.front(); q.pop();
      int tile = 0;
      for (int dir =0; dir <4; ++dir){
        int nx = cur.X +dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny<0 || nx >= n|| ny >=m) continue;
        if (board1[nx][ny] == -1) continue;
        tile++;
      }
      int nval = board1[cur.X][cur.Y] /5;
      board2[cur.X][cur.Y] += board1[cur.X][cur.Y] - nval * tile;
      if (tile == 0) continue;
      for (int dir =0; dir <4; ++dir){
        int nx = cur.X +dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny<0  || nx >= n|| ny >=m) continue;
        if (board1[nx][ny] == -1) continue;
        board2[nx][ny] += nval;
      }
    }
    airPress();
    for (int i = 0; i <n; ++i){
      for (int j = 0; j <m; ++j){
        if (board1[i][j] == -1) continue;
        board1[i][j] = board2[i][j];
        if (board2[i][j] != 0){
          q.push({i,j});
          board2[i][j] = 0;
        }
      }
    }
  }
  for (int i = 0; i <n; ++i)
    for (int j = 0; j <m; ++j)
      ans += board1[i][j];
  cout << ans + 2;
}