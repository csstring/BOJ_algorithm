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
int n,m;
char board[1001][1001];
int Count[1001][1001][2];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i + 1][j + 1];
    }
  }
  Count[1][1][0] = 1;
  Count[1][1][1] = 1;
  queue<tuple<int,int,bool>> q;
  q.push({1,1,0});
  while (!q.empty())
  {
    auto cur = q.front();
    int curx, cury, block;
    tie(curx,cury,block) = cur; 
    q.pop();
    if (curx == n && cury == m)
    {
      cout << Count[curx][cury][block];
      return(0);
    }
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = curx + dx[dir];
      int ny = cury + dy[dir];
      int nblock = 0;
      if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
      if ((board[nx][ny] == '1' && block == 1) || Count[nx][ny][block] != 0) continue;
      if (board[nx][ny] == '1' && block == 0)
      {
        nblock = 1;
        Count[nx][ny][nblock] = Count[curx][cury][block] + 1;
        q.push({nx,ny,nblock});
      }
      else
      {
        Count[nx][ny][block] = Count[curx][cury][block] + 1;
        q.push({nx,ny,block});
      }
    }
  }
  cout << -1;
}