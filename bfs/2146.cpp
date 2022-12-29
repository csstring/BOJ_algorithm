#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n;
int board[100][100];
int Count[100][100];
void fix_island(int x, int y, queue<pair<int,int>> &q, int cnt)
{
  queue<pair<int,int>> temp;
  Count[x][y] = 0;
  board[x][y] = cnt;
  q.push({x,y});
  temp.push({x,y});
  while (!temp.empty())
  {
    pair<int,int> cur = temp.front(); temp.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if (board[nx][ny] == 0 || Count[nx][ny] == 0) continue;
      board[nx][ny] = cnt;
      Count[nx][ny] = 0;
      q.push({nx,ny});
      temp.push({nx,ny});
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i){
    fill(Count[i], Count[i] + n, -1);
    for (int j = 0; j < n; ++j){
      cin >> board[i][j];
    }
  }
  queue<pair<int,int>> q;
  int cnt = 1;
  for (int i = 0; i <n; ++i){
    for (int j = 0; j < n; ++j){
      if (board[i][j] != 0 && Count[i][j] == -1)
        fix_island(i,j,q,cnt);
        cnt++;
    }
  }
  int ans = 999999;
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
      if ((board[nx][ny] != 0) && (board[nx][ny] != board[cur.X][cur.Y]))
      {
        ans = min(Count[nx][ny] + Count[cur.X][cur.Y], ans);
      }
      if (Count[nx][ny] != -1) continue;
      board[nx][ny] = board[cur.X][cur.Y];
      Count[nx][ny] = Count[cur.X][cur.Y] + 1;
      q.push({nx,ny});
    }
  }
  cout <<ans;
}