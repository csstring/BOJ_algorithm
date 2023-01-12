//아기 상어
#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
using namespace std;
deque<pair<int,int>> fish;
queue<pair<int,int>> shark;
int n,ans,eat,sharkSize;
int vis[20][20];
int board[20][20];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
#define X first
#define Y second
void bfs()
{
  while (!shark.empty())
  {
    pair<int,int> cur = shark.front(); shark.pop();
    for (int dir =0; dir <4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
      if (vis[nx][ny] != -1 || board[nx][ny] > sharkSize) continue;
      vis[nx][ny] = vis[cur.X][cur.Y] +1;
      shark.push({nx,ny});
    }
  }
}
deque<pair<int,int>>::iterator eatCheck()
{
  deque<pair<int,int>>::iterator tmp = fish.end();
  int Count = INT32_MAX;
  for (auto it = fish.begin(); it != fish.end(); ++it)
  {
    int x = it->X;
    int y = it->Y;
    if (board[x][y] >= sharkSize) continue;
    if (vis[x][y] >= Count || vis[x][y] == -1) continue;
    Count = vis[x][y];
    tmp = it;
  }
  return tmp;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  sharkSize = 2;
  for (int i = 0; i <n; ++i){
    fill(vis[i], vis[i] +n, -1);
    for (int j = 0; j <n; ++j){
      cin >> board[i][j];
      if (board[i][j] == 9){
        vis[i][j] = 0;
        board[i][j] = 0;
        shark.push({i,j});
      } 
      if (board[i][j] >= 1 && board[i][j] <= 6) fish.push_back({i,j});
    }
  }
  while (1)
  {
    bfs();
    deque<pair<int,int>>::iterator it = eatCheck();
    if (it == fish.end()) break;
    int x = it->X;
    int y = it->Y;
    ans += vis[x][y];
    for (int i =0; i < n; ++i)
      fill(vis[i], vis[i]+n, -1);
    vis[x][y] = 0;
    board[x][y] = 0;
    shark.push({x,y});
    eat++;
    fish.erase(it);
    if (sharkSize == eat){
      eat = 0; sharkSize++;
    }
  }
  cout << ans;
}