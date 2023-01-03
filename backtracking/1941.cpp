#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define X first
#define Y second
char board[25];
int sel[25];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[5][5];
int ans;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 25; ++i){
    cin >> board[i];
  }
  fill(sel + 7, sel +25, 1);
  do{
    char bfsBoard[5][5];
    int S_count = 0;
    int startX = 0; int startY = 0;
    for (int i = 0; i < 25; ++i)
    {
      int x = i / 5; int y = i % 5;
      if (sel[i] == 0){
        if (board[i] == 'S') S_count++;
        bfsBoard[x][y] = 1;
        startX = x;
        startY = y;
      }
      else{
        bfsBoard[x][y] = 0;
      }
    }
    if (S_count < 4) continue;
    for (int i = 0; i < 5; ++i)
      fill(vis[i], vis[i] + 5, 0);
    queue<pair<int,int>> q;
    q.push({startX, startY});
    vis[startX][startY] = 1;
    int sizeCheck=1;
    while (!q.empty())
    {
      pair<int,int> cur = q.front(); q.pop();
      for (int dir = 0; dir <4; dir++)
      {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if (nx < 0 || ny < 0 || nx >=5 || ny >= 5) continue;
        if (vis[nx][ny] || bfsBoard[nx][ny] == 0) continue;
        q.push({nx,ny});
        sizeCheck++;
        vis[nx][ny] = 1;
      }
    }
    if (sizeCheck == 7) ans++;
  }while (next_permutation(sel, sel+25));
  cout << ans;
}