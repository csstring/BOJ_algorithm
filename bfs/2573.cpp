#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
const int origin = 0;
const int Copy = 1;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[300][300][2];
int vis[300][300];
int total,n,m, h, ans;
void melt(int x, int y)
{
  queue<pair<int,int>> q;
  queue<pair<int,int>> temp;
  q.push({x,y});
  temp.push({x,y});
  vis[x][y] = 1;
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    int mel_val = 0;
    for (int dir = 0; dir <4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0|| nx >= n || ny >= m) continue;
      if (board[nx][ny][origin] == 0) mel_val++;
      if (board[nx][ny][origin] == 0 || vis[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      q.push({nx,ny});
      temp.push({nx,ny});
    }
    if (board[cur.X][cur.Y][origin] <= mel_val)
    {
      board[cur.X][cur.Y][Copy] = 0;
      total--;
    }
    else
      board[cur.X][cur.Y][Copy] = board[cur.X][cur.Y][origin] - mel_val;
  }
  while (!temp.empty())
  {
    pair<int,int> cur = temp.front(); temp.pop();
    board[cur.X][cur.Y][origin] = board[cur.X][cur.Y][Copy];
  }
}

bool size_check(int x, int y)
{
  queue<pair<int,int>> q;
  int size = 0;
  q.push({x,y});
  vis[x][y] = -1;
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    size++; 
    for (int dir = 0; dir <4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0|| nx >= n || ny >= m) continue;
      if (board[nx][ny][origin] == 0 || vis[nx][ny] == -1) continue;
      vis[nx][ny] = -1;
      q.push({nx,ny});
    }
  }
  if (size == total)
    return (true);
  return (false);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      cin >> board[i][j][origin];
      if (board[i][j][origin] != 0){
        total++;
      }
    }
  }
  for (int i = 0; i <n; ++i){
    for (int j = 0; j <m; ++j){
      while (board[i][j][origin] != 0)
      {
        if (size_check(i,j) == false)
        {
          cout << ans;
          return (0);
        }
        melt(i,j);
        ans++;
      }
    }
  }
  cout << 0;
}