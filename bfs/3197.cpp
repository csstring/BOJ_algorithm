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
int n,m;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  queue<pair<int,int>> bird;
  int count = 0;
  for (int i = 0; i < n; ++i){
    fill(vis[i], vis[i] + m, -1);
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
      if (board[i][j] == 'L'){
        bird.push({i,j});
        vis[i][j] = count;
        count++;
      }
    }
  }
  while (!bird.empty())
  {
    pair<int,int> curB = bird.front(); bird.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = curB.X + dx[dir];
      int ny = curB.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
      if (vis[nx][ny] == vis[curB.X][curB.Y]) continue;
      if (vis[nx][ny] != -1 && (vis[nx][ny] + 1) % 2 == vis[curB.X][curB.Y]) {
        
        return (0);
      }
      bird.push({nx,ny});
      vis[nx][ny] = vis[curB.X][curB.Y];
    }
  }
}