#include <iostream>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int R,C;
int board[1000][1000];
int Exit[1000][1000];
int fire[1000][1000];
string str;
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<pair<int,int>> jq;
  queue<pair<int,int>> fq;
  cin >> R >> C;
  for (int i = 0; i < R; ++i){
    cin >> str;
    fill(fire[i], fire[i] + C, -1);
    fill(Exit[i], Exit[i] + C, -1);
    for (int j = 0; j < C; ++j){
      board[i][j] = str[j];
      if (board[i][j] == 'J'){
        Exit[i][j] = 0;
        jq.push({i, j});
      }
      else if (board[i][j] == 'F'){
        fire[i][j] = 0;
        fq.push({i,j});
      }
    }
  }
  while (!fq.empty())
  {
    pair<int,int> cur = fq.front();
    fq.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx == R || ny == C) continue;
      if (board[nx][ny] == '#' || fire[nx][ny] != -1) continue;
      fire[nx][ny] = fire[cur.X][cur.Y] + 1;
      fq.push({nx, ny});
    }
  }
  while (!jq.empty())
  {
    pair<int,int> cur = jq.front();
    jq.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if (nx < 0 || ny < 0 || nx == R || ny == C)
      {
        cout << Exit[cur.X][cur.Y] + 1;
        return (0);
      }
      if (board[nx][ny] == '#' || Exit[nx][ny] != -1) continue;
      if (fire[nx][ny] != -1 && fire[nx][ny] <= Exit[cur.X][cur.Y] + 1) continue;
      Exit[nx][ny] = Exit[cur.X][cur.Y] + 1;
      jq.push({nx, ny});
    }
  }
  cout << "IMPOSSIBLE";
}