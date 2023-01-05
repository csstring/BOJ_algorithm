//puyo puyo
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
#define X first
#define Y second
const int n = 12;
const int m = 6;
int dx[4] = {-1, 0,1,0};
int dy[4] = {0,1,0,-1};
int ans;
char board[12][6];
void rebuild()
{
  char tmp[12];
  for (int j = 0; j <m ; ++j)
  {
    fill(tmp, tmp +n, '.');
    int index = 11;
    for (int i = 11; i >= 0 ;--i){
      if (board[i][j] == '.') continue;
      tmp[index] = board[i][j];
      index--;
    }
    for (int i = 11; i >= 0 ; --i)
      board[i][j] = tmp[i];
  }
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i =0; i <n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
    }
  }
  while (1)
  {
    bool flag = false;
    bool vis[12][6];
    for (int i = 0; i <n; ++i)
      fill(vis[i], vis[i] + m, 0);
    for (int i = 0; i <n; ++i){
      for (int j = 0; j <m; ++j)
      {
        if (vis[i][j] || board[i][j] == '.') continue;
        queue<pair<int,int>> q;
        stack<pair<int,int>> boom;
        boom.push({i,j});
        q.push({i,j}); vis[i][j] = 1;
        while (!q.empty())
        {
          pair<int,int> cur = q.front(); q.pop();
          for (int dir =0; dir <4; ++dir)
          {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx <0 || ny < 0|| nx >=n || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
            boom.push({nx,ny});
          }
        }
        if (boom.size() >= 4) {
          flag = true;
          int size= boom.size();
          for (int i = 0; i< size; ++i)
          {
            pair<int,int> cur = boom.top(); boom.pop();
            board[cur.X][cur.Y] = '.';
          }
        }
      }
    }
    rebuild();
    if (flag == false) break;
    ans++;
  }
  cout << ans;
}