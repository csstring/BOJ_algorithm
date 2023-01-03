#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define RED 1
#define GREEN 2
#define FLOWER 3
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m,r,g, ans;
vector<int> back;
pair<int,int> backxy[11];
int board[52][52];

int run()
{
  int total = 0;
  int vis[52][52];
  int bfsBoard[52][52];
  for (int i = 0; i<n; ++i){
    fill(vis[i], vis[i] + m, -1);
    fill(bfsBoard[i], bfsBoard[i] + m, 0);
  }
  queue<pair<int,int>> q;
  for (int i = 0; i < back.size(); ++i){
    bfsBoard[backxy[i].X][backxy[i].Y] = back[i];
    if (back[i] != 0) 
    {
      vis[backxy[i].X][backxy[i].Y] = 0;
      q.push({backxy[i].X,backxy[i].Y});
    }
  }
  while (!q.empty())
  {
    pair<int,int> cur = q.front(); q.pop();
    if (bfsBoard[cur.X][cur.Y] == FLOWER) continue;
    for (int dir =0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (board[nx][ny] == 0 || bfsBoard[nx][ny] == bfsBoard[cur.X][cur.Y] || bfsBoard[nx][ny] == FLOWER) continue;
      if (vis[nx][ny] != -1 && bfsBoard[nx][ny] != bfsBoard[cur.X][cur.Y])
      {
        if (vis[nx][ny] == vis[cur.X][cur.Y] + 1)
        {
          total++;
          bfsBoard[nx][ny] = FLOWER;
        }
        continue;
      }
      q.push({nx,ny});
      vis[nx][ny] = vis[cur.X][cur.Y] + 1;
      bfsBoard[nx][ny] = bfsBoard[cur.X][cur.Y];
    }
  }
  return (total);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ground = 0;
  cin >> n >> m >> r >> g;
  for (int i = 0; i < n ; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
      if (board[i][j] == 2)
      {
        backxy[ground].X = i;
        backxy[ground].Y = j;
        ground++;
      }
    }
  }
  for (int i = 0; i < ground; ++i){
    if (r > 0) {
      back.push_back(RED);
      r--;
    }
    else if (g > 0){
      back.push_back(GREEN);
      g--;
    }
    else
      back.push_back(0);
  }
  sort(back.begin(), back.end());
  do{
    ans = max(ans, run());
  }while (next_permutation(back.begin(), back.end()));
  cout << ans;
}