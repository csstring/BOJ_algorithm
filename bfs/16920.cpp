//확장 게임
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
queue<tuple<int,int,int>> q[11];
int turnArr[11];
int ans[11];
int n,m,p,s;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for (int i = 1; i <= p; ++i){
    cin >> s; turnArr[i] = s;
  }
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      cin >> board[i][j];
      if (board[i][j] != '.' && board[i][j] != '#')
        q[board[i][j] - 48].push({i,j,0});
    }
  }
  int game_turn = 0;
  int flag = 0;
  while(1)
  {
    game_turn++;
    for (int i = 1; i <= p; ++i){
      if (!q[i].empty()) break;
      if (i == p && q[i].empty()) flag = 1;
    }
    if (flag) break;
    for (int i = 1; i <=p; ++i)
    {
      int limit_turn = turnArr[i] * game_turn;
      queue<tuple<int,int,int>> &curQ = q[i];
      while (!curQ.empty())
      {
        int curX,curY,curT;
        tie(curX,curY,curT) = curQ.front();
        if (curT == limit_turn) break;
        curQ.pop();
        for (int dir = 0; dir <4; ++dir)
        {
          int nx = curX + dx[dir];
          int ny = curY + dy[dir];
          if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
          if (board[nx][ny] != '.') continue;
          board[nx][ny] = board[curX][curY];
          curQ.push({nx,ny,curT + 1});
        }
      }
    }
  }
  int temp = 0;
  for (int i = 0; i < n; ++i){
    for (int j = 0; j < m; ++j){
      temp = board[i][j];
      if (temp != '.' && temp != '#')
        ans[temp - 48]++;
    }
  }
  for (int i =1 ; i <= p; ++i)
    cout << ans[i] << ' ';
}