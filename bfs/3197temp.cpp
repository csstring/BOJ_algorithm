//백조의 호수
#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
char board[1501][1501];
int vis[1501][1501];
int icevis[1501][1501];
int n,m,lx,ly;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  queue<pair<int,int>> ice1;
  queue<pair<int,int>> ice2;
  queue<pair<int,int>> bird1;
  queue<pair<int,int>> bird2;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
      if (board[i][j] == 'L'){
        lx = i;
        ly = j;
      }
      if (board[i][j] != 'X') ice1.push({i,j}); 
    }
  }
  bird1.push({lx,ly});
  board[lx][ly] = '.';
  vis[lx][ly] = 1;
  int time = 0;
  while (1)
  {
    while (!bird1.empty())
    {
      pair<int,int> curB = bird1.front(); bird1.pop();
      for (int dir = 0; dir < 4; ++dir)
      {
        int nx = curB.X + dx[dir];
        int ny = curB.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] == 1) continue;
        if (board[nx][ny] == 'X'){
          bird2.push({nx,ny});
          vis[nx][ny] = 1;
          continue;
        }
        if (board[nx][ny] == 'L') {
          cout << time;
          return (0);
        }
        bird1.push({nx,ny});
        vis[nx][ny] = 1;
      }
    }
    while (!bird2.empty())
    {
      pair<int,int> cur = bird2.front(); bird2.pop();
      bird1.push({cur.X, cur.Y});
    }
    while (!ice1.empty())
    {
      pair<int,int> cur = ice1.front(); ice1.pop();
      for (int dir = 0; dir <4; ++dir)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || icevis[nx][ny] == 1) continue;
        if (board[nx][ny] == 'X'){
          ice2.push({nx,ny});
        }
        icevis[nx][ny] = 1;
      }
    }
    while (!ice2.empty()){
      auto cur = ice2.front(); ice2.pop();
      board[cur.X][cur.Y] = '.';
      ice1.push({cur.X,cur.Y});
    }
    time++;
  }
}