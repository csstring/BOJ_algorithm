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
char board[1000][1000];
int Count[11][1000][1000];
int n, m, k;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for (int i = 0 ;i <n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
    }
  }
  queue<tuple<int,int,int>> q;
  q.push({0,0,0});
  Count[0][0][0] = 1;
  while (!q.empty())
  {
    int curX, curY, broken;
    tie(curX, curY, broken) = q.front(); q.pop();
    if (Count[broken][n - 1][m - 1] != 0)
    {
      cout << Count[broken][n - 1][m - 1];
      return (0);
    }
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = curX + dx[dir];
      int ny = curY + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      int newbroken = broken;
      if (board[nx][ny] == '1') newbroken++;
      if (newbroken > k || Count[newbroken][nx][ny] != 0) continue;
      Count[newbroken][nx][ny] = Count[broken][curX][curY] + 1;
      q.push({nx,ny,newbroken});
    }
  }
  cout << -1;
}